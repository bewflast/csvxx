#ifndef CSVXX_WINDOWS_HPP
#define CSVXX_WINDOWS_HPP

# define WIN32_LEAN_AND_MEAN
# include <Windows.h>

namespace platform
{
	using fileSize 			= DWORD;
	using fileHandle 		= HANDLE;
	using fileMapping		= LPCVOID;
	using unmapResultType	= BOOL;
	using closeFileFuncType	= BOOL (*)(fileHandle);

	inline closeFileFuncType closeFile 	= CloseHandle;

	fileSize 		getFileSize( fileHandle file );
	fileHandle 		createFile( const char* filePath );
	fileHandle		createFileMappingHandle( fileHandle file );
	fileMapping 	createMappedViewOfFile( fileHandle fileDescriptor, fileSize fSize );
	unmapResultType	unmap( fileMapping map, fileSize len );

}


# define SHOULD_HAVE_MEMMAP_HANDLE

# define INVALID_DESCRIPTOR 	INVALID_HANDLE_VALUE
# define GET_SYSTEM_ERROR_NUM 	static_cast<int>(GetLastError())
# define INVALID_MEMMAP_HANDLE	NULL

#endif //CSVXX_WINDOWS_HPP
