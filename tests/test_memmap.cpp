#include "tests.hpp"

TEST(memMap, unsuccessfullyMappedFile)
{
	EXPECT_THROW(platform::MemoryMap("notExistingFile"), CSVXX::SystemException);
}

TEST(memMap, successfullyMappedFile)
{
	platform::MemoryMap makaka(DATA_FILE("a.txt"));

	EXPECT_FALSE(makaka.getData() == NULL);
}

TEST(memMap, dataIsSame)
{
	std::string_view testFileContent = "gkfdgdffgdhjfdghkghghjkghjktyukjhgkghjkhgjkghjkghjkghjjdfghklgdfjg546";

	std::ofstream testFileInput(DATA_FILE("tempMmapTest.txt"));
	testFileInput << testFileContent;
	testFileInput.close();

	platform::MemoryMap	memoryMap(DATA_FILE("tempMmapTest.txt"));
	std::string_view memMapData{reinterpret_cast<const char*>(memoryMap.getData())};

	EXPECT_EQ(testFileContent, memMapData);
}

TEST(memMap, dataIsSameWithIfstreamBuf)
{
	std::ifstream	file(DATA_FILE("a.txt"));
	std::stringstream fileStream;
	fileStream << file.rdbuf();
	std::string fileContent(fileStream.str());
	file.close();

	platform::MemoryMap mappedFile(DATA_FILE("a.txt"));
	std::string mappedFileContent {reinterpret_cast<const char*>(mappedFile.getData())};

	fileContent.erase(std::remove(fileContent.begin(), fileContent.end(), '\r'),
					  fileContent.end());
	mappedFileContent.erase(std::remove(mappedFileContent.begin(), mappedFileContent.end(), '\r'),
							mappedFileContent.end());

	EXPECT_EQ(fileContent, mappedFileContent);
}