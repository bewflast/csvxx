#ifndef CSVXX_LINUX_HPP
#define CSVXX_LINUX_HPP

# include <sys/mman.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <unistd.h>

namespace platform
{
	using fileSize 			= size_t;
	using fileHandle 		= int;
	using fileMapping		= void*;
	using unmapResultType	= int;
	using closeFileFuncType	= int (*)(fileHandle);

	inline closeFileFuncType closeFile 	= close;

	fileSize 		getFileSize( fileHandle file );
	fileHandle 		createFile( const char* filePath );
	fileMapping 	createMappedViewOfFile( fileHandle fileDescriptor, fileSize fSize );
	unmapResultType	unmap( fileMapping map, fileSize len );


}

# define INVALID_DESCRIPTOR 	static_cast<int>(-1)
# define GET_SYSTEM_ERROR_NUM 	static_cast<int>(errno)
# define INVALID_MEMMAP_HANDLE	MAP_FAILED
# define INVALID_CLOSE_DESC_VAL	static_cast<int>(-1)

#endif //CSVXX_LINUX_HPP
