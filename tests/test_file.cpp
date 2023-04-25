#include "tests.hpp"

TEST(file, notExistingFileOpeningFailure)
{
	EXPECT_THROW(platform::File("notExistableFile"), CSVXX::SystemException);
}

TEST(file, existingFileOpeningSuccess)
{
	EXPECT_NO_THROW(platform::File(DATA_FILE("a.txt")));
}

TEST(file, correctFileSize)
{
	std::string_view testFileContent = "1234567890sdjagjdklfshfdjhgsjdfghskdlfgsldkfjhsdklfsd";
	std::ofstream testFileInput(DATA_FILE("temp.txt"));

	testFileInput << testFileContent;
	testFileInput.close();

	platform::File file(DATA_FILE("temp.txt"));

	EXPECT_EQ(file.getSize(), testFileContent.size());
}