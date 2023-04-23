#include <gtest/gtest.h>
#include <iostream>
#include <fstream>
#include <FileBase/MemoryMap.hpp>

TEST(memMap, unsuccessfullyMappedFile)
{
	EXPECT_THROW(platform::MemoryMap("notExistingFile"), CSVXX::SystemException);
}

TEST(memMap, successfullyMappedFile)
{
	platform::MemoryMap makaka("../data/a.txt");

	EXPECT_FALSE(makaka.getData() == NULL);
}

TEST(memMap, dataIsSame)
{
	std::string_view testFileContent = "gkfdgdffgdhjfdghkghghjkghjktyukjhgkghjkhgjkghjkghjkghjjdfghklgdfjg546";

	std::ofstream testFileInput("../data/tempMmapTest.txt");
	testFileInput << testFileContent;
	testFileInput.close();

	platform::MemoryMap	memoryMap("../data/tempMmapTest.txt");
	std::string_view memMapData{reinterpret_cast<const char*>(memoryMap.getData()), memoryMap.dataLength()};

	EXPECT_EQ(testFileContent, memMapData);
}
