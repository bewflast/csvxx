#include "FileBase/File.hpp"

platform::File::File(const char *filePath)
:
		_fd(platform::createFile(filePath))
{

	if (!_fd.isValid())
		throw(CSVXX::SystemException("Failed to create file descriptor: "));

	_size = platform::getFileSize(static_cast<platform::fileHandle>(_fd));
}

platform::fileSize platform::File::getSize() const noexcept
{
	return _size;
}


platform::fileHandle platform::File::getDescriptor() const noexcept
{
	return static_cast<platform::fileHandle>(_fd);
}
