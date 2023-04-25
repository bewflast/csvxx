#include "FileBase/platformDefines/platform.hpp"

using platform::fileSize;
using platform::fileHandle;
using platform::fileMapping;
using platform::unmapResultType;
using platform::closeFileFuncType;

fileHandle platform::createFile(const char *filePath)
{
	platform::fileHandle file {CreateFile(filePath, GENERIC_READ, 0, nullptr, OPEN_EXISTING, FILE_ATTRIBUTE_READONLY,
										  nullptr)};
	return file;
}

fileSize platform::getFileSize(fileHandle file)
{
	LARGE_INTEGER fileSize;

	if (!GetFileSizeEx(file, &fileSize))
		throw (CSVXX::SystemException("Failed to get size of file"));

	return (static_cast<::fileSize>(fileSize.QuadPart));
}

fileHandle	platform::createFileMappingHandle( fileHandle file )
{
	fileHandle mapping {CreateFileMapping(file, nullptr, PAGE_READONLY, 0, 0, nullptr)};

	return mapping;
}

fileMapping platform::createMappedViewOfFile( fileHandle fileDescriptor, fileSize fSize )
{
	fileMapping viewOfFile {MapViewOfFile(fileDescriptor, FILE_MAP_READ,  0, 0, fSize)};

	return viewOfFile;
}

unmapResultType platform::unmap( fileMapping map, fileSize len )
{
	return UnmapViewOfFile(map);
}

