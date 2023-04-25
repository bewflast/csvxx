#include "tests.hpp"

TEST(fileBase, yeah)
{
	platform::FileBase test(DATA_FILE("b.csv"));

	//EXPECT_FALSE(test.getRawFileContent().empty());


}