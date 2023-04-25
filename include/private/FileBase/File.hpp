#ifndef CSVXX_FILE_HPP
#define CSVXX_FILE_HPP

# include "UniqueFileDescriptor.hpp"

namespace platform
{
	class File;
}

class platform::File final
{
public:
	explicit File( const char* filePath );

	[[nodiscard]]
	platform::fileSize getSize() const noexcept;

	[[nodiscard]]
	platform::fileHandle getDescriptor() const noexcept;

	File() 												= delete;
	File( const File& other ) 							= delete;
	File( const File&& other ) 				noexcept 	= delete;
	File& operator=( const File& other ) 				= delete;
	File& operator=( const File&& other )	noexcept	= delete;

private:
	platform::UniqueFileDescriptor _fd;
	platform::fileSize _size = 0;
};
#endif //CSVXX_FILE_HPP
