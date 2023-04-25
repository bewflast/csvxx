#include "FileBase/FileBase.hpp"
#include <immintrin.h>
#include <vector>
#include <iostream>
#include <thread>
#include <unordered_map>
platform::FileBase::FileBase( const char* filePath )
:
		_mappedData(filePath),
		_dataPtr(reinterpret_cast<const char8_t*>(_mappedData.getData())),
		_rawFileContent(u8"s")
{
	const auto dataLen = _mappedData.dataLength();

	uint64_t newlines = 0;

	/*uint64_t i = 0;
		for (i = 0; i < dataLen; ++i)
		if (_dataPtr[i] == '\n')
			++newlines;*/

	uint64_t dolki = dataLen / (15);

	std::vector<std::thread> threads;
	std::unordered_map<std::thread::id, uint64_t> zhopa;
	for (int i = 0; i < 15; ++i)
		threads.emplace_back([&zhopa, this](uint64_t from, uint64_t to)
		{
			uint64_t result {0};
			__m256i newline = _mm256_set1_epi8('\n');
			const char8_t* ptr = _dataPtr + from;


			for (; ptr <= _dataPtr + (to - 32); ptr += 32)
			{
				__m256i data = _mm256_loadu_si256((__m256i*)ptr);
				int mask = _mm256_movemask_epi8(_mm256_cmpeq_epi8(data, newline));
				if (mask)
					result++;
			}

			ptr = _dataPtr + from;
			std::vector<uint64_t> indexes(result);
			/*uint64_t counter {0};
			for (; ptr <= _dataPtr + (to - 32); ptr += 32)
			{
				__m256i data = _mm256_loadu_si256((__m256i*)ptr);
				unsigned long mask = _mm256_movemask_epi8(_mm256_cmpeq_epi8(data, newline));
				if (mask)
					indexes[counter++] = ptr - _dataPtr + __builtin_ctzl(mask);


			}*/
			zhopa.emplace(std::this_thread::get_id(), result);
		}, dolki*i, dolki*(i+1));
	for (auto& thr : threads)
		thr.join();
	for (const auto& [threadID, value] : zhopa)
		newlines += value;
	std::cout << std::thread::hardware_concurrency() << " " << dataLen << " " << newlines <<  std::endl;
}

std::u8string_view platform::FileBase::getRawFileContent() const noexcept
{
	return _rawFileContent;
}

const char8_t* platform::FileBase::getDataPtr() const noexcept
{
	return _dataPtr;
}