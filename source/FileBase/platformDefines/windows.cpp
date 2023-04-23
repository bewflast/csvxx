#include "FileBase/platformDefines/platform.hpp"

platform::fileHandle platform::createFile(const char *filePath)
{
	platform::fileHandle file {CreateFile(filePath, GENERIC_READ, 0, nullptr, OPEN_EXISTING, FILE_ATTRIBUTE_READONLY,
										  nullptr)};
	return file;
}

platform::fileSize platform::getFileSize(fileHandle file)
{
	LARGE_INTEGER fileSize;

	if (!GetFileSizeEx(file, &fileSize))
		throw (CSVXX::SystemException("Failed to get size of file"));

	return (static_cast<platform::fileSize>(fileSize.QuadPart));
}

platform::fileHandle	platform::createFileMappingHandle( platform::fileHandle file )
{
	platform::fileHandle mapping {CreateFileMapping(file, nullptr, PAGE_READONLY, 0, 0, nullptr)};

	return mapping;
}

platform::fileMapping platform::createMappedViewOfFile( platform::fileHandle fileDescriptor, platform::fileSize fSize )
{
	platform::fileMapping viewOfFile {MapViewOfFile(fileDescriptor, FILE_MAP_READ,  0, 0, fSize)};

	return viewOfFile;
}

