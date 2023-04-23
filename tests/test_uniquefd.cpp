#include <gtest/gtest.h>
#include "FileBase/UniqueFileDescriptor.hpp"

TEST(uniqueFD, invalidFileDescriptor)
{
	platform::UniqueFileDescriptor fd(platform::createFile("notExistingFile"));

	EXPECT_FALSE(fd.isValid());
}

TEST(uniqueFD, validFileDescriptor)
{
	platform::UniqueFileDescriptor fd(platform::createFile("../data/a.txt"));

	EXPECT_TRUE(fd.isValid());
}

TEST(uniqueFD, invalidFdAfterMoveAssignment)
{
	platform::UniqueFileDescriptor fd(platform::createFile("../data/a.txt"));
	platform::UniqueFileDescriptor otherFd(platform::createFile("notExisting"));

	EXPECT_TRUE(fd.isValid());
	EXPECT_FALSE(otherFd.isValid());

	otherFd = std::move(fd);

	EXPECT_FALSE(fd.isValid());
	EXPECT_TRUE(otherFd.isValid());
}

TEST(uniqueFD, invalidFdAfterMoveConstruction)
{
	platform::UniqueFileDescriptor fd(platform::createFile("../data/a.txt"));
	EXPECT_TRUE(fd.isValid());
	platform::UniqueFileDescriptor otherFd(std::move(fd));

	EXPECT_FALSE(fd.isValid());
	EXPECT_TRUE(otherFd.isValid());
}