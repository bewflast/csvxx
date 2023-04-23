#ifndef CSVXX_MEMORYMAP_HPP
#define CSVXX_MEMORYMAP_HPP

# include "File.hpp"

namespace platform
{
	class MemoryMap;
}

class platform::MemoryMap
{

public:
	explicit MemoryMap( const char* pathToFileForMapping );
	~MemoryMap();

	[[nodiscard]]
	const std::byte*	getData() const noexcept;

	[[nodiscard]]
	platform::fileSize	dataLength() const noexcept;

private:
	platform::File		_fileToMap;
	platform::fileSize	_dataLen;
	const std::byte*	_data;

# ifdef SHOULD_HAVE_MEMMAP_HANDLE
	platform::UniqueFileDescriptor _memmapDescriptor = static_cast<platform::UniqueFileDescriptor>(INVALID_DESCRIPTOR);
# endif

};

#endif //CSVXX_MEMORYMAP_HPP
