#include "DataFrame.hpp"
#include "FileBase/FileBase.hpp"
#include <ctime>
#include <iostream>
CSVXX::DataFrame::DataFrame(std::filesystem::path filePath )
:
	_systemFile 	{std::make_unique<CSVXX::FileBase>(filePath)},
	_headers		{""},
	_linesPositions	{},
	_linesNumber		{0},
	_dataRaw		{reinterpret_cast<const char*>(_systemFile->_data)}
{
	uint32_t prevPos {0};
	time_t now {std::time(nullptr)};

	for (std::size_t i = 0; _dataRaw[i]; i++)
	{
		if (_dataRaw[i] == '\n')
		{
			_linesPositions.push_back(prevPos);
			prevPos = i + 1;
		}
	}

	_linesNumber = _linesPositions.size();
};


std::string CSVXX::DataFrame::getLine(std::size_t lineNum)
{
	if (lineNum > _linesPositions.size() - 1)
		return ("");
	return   { _dataRaw + _linesPositions[lineNum - 1], _linesPositions[lineNum] - _linesPositions[lineNum - 1]  } ;

}

CSVXX::DataFrame::~DataFrame(){};