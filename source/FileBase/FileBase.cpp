#include "FileBase/FileBase.hpp"


CSVXX::FileBase::FileBase (std::filesystem::path& filePath )
:
	_hFile(nullptr),
	_hFileMap(nullptr),
	_fileSize(0),
	_filePath(filePath),
	_fileName(filePath.filename()),
	_data(nullptr)
{

	_hFile 		= CreateFile(filePath.c_str(),
							   GENERIC_READ | GENERIC_WRITE | GENERIC_EXECUTE,
							   0,
							   nullptr,
							   OPEN_EXISTING,
							   FILE_ATTRIBUTE_NORMAL,
							   nullptr);
	_fileSize 		= GetFileSize(_hFile, nullptr);
	_hFileMap 		= CreateFileMapping(_hFile,
										 nullptr,
										 PAGE_EXECUTE_READWRITE,
										 0,
										 0,
										 nullptr);
	_data = static_cast<std::byte*>(MapViewOfFile(_hFileMap, FILE_MAP_ALL_ACCESS, 0, 0, _fileSize));

};


CSVXX::FileBase::~FileBase()
{
	UnmapViewOfFile(static_cast<LPCVOID>(_data));
	platform::closeFile(_hFileMap);
	platform::closeFile(_hFile);
}