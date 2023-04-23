#ifndef CSVXX_WINDOWS_HPP
#define CSVXX_WINDOWS_HPP

# include <Windows.h>

namespace platform
{
	using fileSize 			= DWORD;
	using fileHandle 		= HANDLE;
	using fileMapping		= LPCVOID;
	using closeFileFuncType	= BOOL (*)(fileHandle);
	using unmapViewFuncType	= BOOL (*)(fileMapping);

	inline closeFileFuncType closeFile 	= CloseHandle;
	inline unmapViewFuncType unmapView	= UnmapViewOfFile;

	fileSize 	getFileSize( fileHandle file );
	fileHandle 	createFile( const char* filePath );
	fileHandle	createFileMappingHandle( fileHandle file );
	fileMapping createMappedViewOfFile( fileHandle fileDescriptor, fileSize fSize );

}

# define INVALID_DESCRIPTOR INVALID_HANDLE_VALUE
# define SHOULD_HAVE_MEMMAP_HANDLE
# define WIN32_LEAN_AND_MEAN
# define VC_EXTRALEAN

#endif //CSVXX_WINDOWS_HPP
