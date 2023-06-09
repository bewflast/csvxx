#include "FileBase/MemoryMap.hpp"


#ifdef SHOULD_HAVE_MEMMAP_HANDLE
platform::MemoryMap::MemoryMap( const char* pathToFileForMapping )
:
		_fileToMap(pathToFileForMapping),
		_dataLen(_fileToMap.getSize()),
		_data(nullptr),
		_memmapDescriptor(platform::createFileMappingHandle(_fileToMap.getDescriptor()))
{
	if (!_memmapDescriptor.isValid())
		throw (CSVXX::SystemException("Failed to create file mapping handle: "));

	_data = static_cast<const std::byte*>(platform::createMappedViewOfFile(
			static_cast<platform::fileHandle>(_memmapDescriptor),
			_dataLen));
	if (!_data)
		throw (CSVXX::SystemException("Failed to map view of file: "));
}

# else

platform::MemoryMap::MemoryMap( const char* pathToFileForMapping )
:
		_fileToMap(pathToFileForMapping),
		_dataLen(_fileToMap.getSize()),
		_data(nullptr)
{
	platform::fileMapping memMap{ platform::createMappedViewOfFile(
			static_cast<platform::fileHandle>(_fileToMap.getDescriptor()),
			_fileToMap.getSize()) };

	if (memMap == INVALID_MEMMAP_HANDLE)
		throw (CSVXX::SystemException("Failed to map view of file: "));

	_data = static_cast<const std::byte*>(memMap);
}

#endif

const std::byte*	platform::MemoryMap::getData() const noexcept
{
	return _data;
}

platform::MemoryMap::~MemoryMap()
{
	platform::unmap(static_cast<platform::fileMapping>(const_cast<std::byte*>(_data)), dataLength());
}

platform::fileSize platform::MemoryMap::dataLength() const noexcept
{
	return _dataLen;
}