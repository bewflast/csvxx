#ifndef CSVXX_FILE_HPP
#define CSVXX_FILE_HPP

# include "UniqueFileDescriptor.hpp"

namespace platform
{
	class File;
}

class platform::File
{
public:
	explicit File( const char* filePath );

	[[nodiscard]]
	platform::fileSize getSize() const noexcept;

	[[nodiscard]]
	platform::fileHandle getDescriptor() const noexcept;

private:
	platform::UniqueFileDescriptor _fd;
	platform::fileSize _size = 0;
};
#endif //CSVXX_FILE_HPP
