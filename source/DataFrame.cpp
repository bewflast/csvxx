#include "DataFrame.hpp"
#include "FileBase/FileBase.hpp"
#include <ctime>
#include <iostream>
CSVXX::DataFrame::DataFrame(std::filesystem::path filePath )
:
	_systemFile 	{std::make_unique<platform::FileBase>((const char*)filePath.c_str())},
	_linesNumber		{0}
{};

