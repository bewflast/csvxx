#include <fstream>
#include <gtest/gtest.h>
#include <FileBase/File.hpp>

TEST(file, notExistingFileOpeningFailure)
{
	EXPECT_THROW(platform::File("notExistableFile"), CSVXX::SystemException);
}

TEST(file, existingFileOpeningSuccess)
{
	EXPECT_NO_THROW(platform::File("../data/a.txt"));
}

TEST(file, correctFileSize)
{
	std::string_view testFileContent = "1234567890sdjagjdklfshfdjhgsjdfghskdlfgsldkfjhsdklfsd";
	std::ofstream testFileInput("../data/temp.txt");

	testFileInput << testFileContent;
	testFileInput.close();

	platform::File file("../data/temp.txt");

	EXPECT_EQ(file.getSize(), testFileContent.size());
}