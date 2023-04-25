//
// Created by bewflast on 22.02.2023.
//

#ifndef CSV_DATAFRAME_HPP
#define CSV_DATAFRAME_HPP

namespace CSVXX
{
	class DataFrame;
}
namespace platform
{
	class FileBase;
}
# include <vector>
# include <string_view>
# include <filesystem>
# include <memory>
class CSVXX::DataFrame
{
	std::unique_ptr<platform::FileBase> _systemFile;

public:
	std::size_t 			_linesNumber;
	explicit DataFrame( std::filesystem::path filePath );

};


#endif
