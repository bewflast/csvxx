#ifndef CSV_FILEBASE_HPP
#define CSV_FILEBASE_HPP

# include <string_view>
# include "MemoryMap.hpp"

namespace platform
{
	class FileBase;
}

class platform::FileBase final
{
public:
	explicit FileBase(  const char* filePath );

	std::u8string_view getRawFileContent() const noexcept;
	const char8_t* getDataPtr() const noexcept;

private:
	platform::MemoryMap		_mappedData;
	const char8_t*			_dataPtr;
	std::u8string_view 		_rawFileContent;
};


#endif
