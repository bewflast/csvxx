#ifndef CSVXX_MEMORYMAP_HPP
#define CSVXX_MEMORYMAP_HPP

# include "File.hpp"

namespace platform
{
	class MemoryMap;
}

class platform::MemoryMap final
{

public:
	explicit MemoryMap( const char* pathToFileForMapping );
	~MemoryMap();

	[[nodiscard]]
	const std::byte*	getData() const noexcept;

	[[nodiscard]]
	platform::fileSize	dataLength() const noexcept;

	MemoryMap() 												= delete;
	MemoryMap( const MemoryMap& other ) 						= delete;
	MemoryMap( const MemoryMap&& other ) 			noexcept 	= delete;
	MemoryMap& operator=( const MemoryMap& other ) 				= delete;
	MemoryMap& operator=( const MemoryMap&& other )	noexcept	= delete;

private:
	platform::File		_fileToMap;
	platform::fileSize	_dataLen;
	const std::byte*	_data;

# ifdef SHOULD_HAVE_MEMMAP_HANDLE
	platform::UniqueFileDescriptor _memmapDescriptor = static_cast<platform::UniqueFileDescriptor>(INVALID_DESCRIPTOR);
# endif

};

#endif //CSVXX_MEMORYMAP_HPP
