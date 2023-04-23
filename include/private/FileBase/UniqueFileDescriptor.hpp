#ifndef CSVXX_UNIQUEFILEDESCRIPTOR_HPP
#define CSVXX_UNIQUEFILEDESCRIPTOR_HPP

# include "platformDefines/platform.hpp"

namespace platform
{
	class UniqueFileDescriptor;
}

class platform::UniqueFileDescriptor
{

public:
	explicit UniqueFileDescriptor( platform::fileHandle fd );
	UniqueFileDescriptor( UniqueFileDescriptor&& other )	 	noexcept;
	UniqueFileDescriptor& operator=( UniqueFileDescriptor&& )	noexcept;
	~UniqueFileDescriptor();

	explicit operator platform::fileHandle() const;

	[[nodiscard]]
	bool isValid() const noexcept;

	UniqueFileDescriptor( const UniqueFileDescriptor& other ) 					= delete;
	UniqueFileDescriptor& operator=( const UniqueFileDescriptor& other ) 		= delete;

private:
	void 		reset() noexcept;

	[[nodiscard]]
	fileHandle 	get() const noexcept;

	fileHandle _descriptor = INVALID_DESCRIPTOR;

};
#endif //CSVXX_UNIQUEFILEDESCRIPTOR_HPP
