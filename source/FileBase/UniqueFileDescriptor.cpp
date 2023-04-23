#include "FileBase/UniqueFileDescriptor.hpp"

platform::UniqueFileDescriptor::UniqueFileDescriptor(platform::fileHandle fd)
:
	_descriptor(fd)
{};

platform::UniqueFileDescriptor::UniqueFileDescriptor(UniqueFileDescriptor &&other) noexcept
:
	_descriptor(other.get())
{
	other.reset();
};

platform::UniqueFileDescriptor& platform::UniqueFileDescriptor::operator=(UniqueFileDescriptor &&other) noexcept
{
	this->_descriptor = other.get();
	other.reset();

	return *this;
};

bool platform::UniqueFileDescriptor::isValid() const noexcept
{
	return _descriptor != INVALID_DESCRIPTOR;
}

platform::fileHandle platform::UniqueFileDescriptor::get() const noexcept
{
	return _descriptor;
}

void platform::UniqueFileDescriptor::reset() noexcept
{
	_descriptor = INVALID_DESCRIPTOR;
}

platform::UniqueFileDescriptor::~UniqueFileDescriptor()
{
	if (this->isValid())
		platform::closeFile(_descriptor);
}

platform::UniqueFileDescriptor::operator platform::fileHandle() const
{
	return _descriptor;
}