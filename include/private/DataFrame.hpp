//
// Created by bewflast on 22.02.2023.
//

#ifndef CSV_DATAFRAME_HPP
#define CSV_DATAFRAME_HPP

namespace CSVXX
{
	class FileBase;
	class DataFrame;
}

# include <vector>
# include <string_view>
# include <filesystem>
# include <memory>
class CSVXX::DataFrame
{
	std::unique_ptr<CSVXX::FileBase> _systemFile;
	std::string_view		_headers;

	const char*				_dataRaw;
	std::vector<uint32_t>	_linesPositions;

public:
	std::size_t 			_linesNumber;
	explicit DataFrame( std::filesystem::path filePath );
	~DataFrame();

	std::string	getLine( std::size_t lineNum );
};


#endif
