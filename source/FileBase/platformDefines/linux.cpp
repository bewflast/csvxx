#include "FileBase/platformDefines/platform.hpp"

using platform::fileSize;
using platform::fileHandle;
using platform::fileMapping;
using platform::unmapResultType;
using platform::closeFileFuncType;

fileHandle platform::createFile( const char* filePath )
{
	platform::fileHandle file {open(filePath, O_RDONLY)};

	return file;
}

fileSize platform::getFileSize(fileHandle file)
{
	struct stat64	fileStats{};

	if (fstat64(file, &fileStats) == -1)
		throw (CSVXX::SystemException("Failed to get size of file"));

	return static_cast<::fileSize>(fileStats.st_size);
}

fileMapping platform::createMappedViewOfFile(fileHandle fileDescriptor, fileSize fSize)
{
	::fileMapping memMap {mmap(nullptr, fSize, PROT_READ, MAP_PRIVATE, fileDescriptor, 0)};

	return memMap;
}

unmapResultType platform::unmap(fileMapping map, fileSize len)
{
	return munmap(map, len);
}