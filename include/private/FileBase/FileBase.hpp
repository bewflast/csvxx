#ifndef CSV_FILEBASE_HPP
#define CSV_FILEBASE_HPP
#define UNICODE

namespace CSVXX
{
	class FileBase;
	class DataFrame;
}

# include "platformDefines/platform.hpp"
# include <memory>
# include <filesystem>
# include <string_view>

class CSVXX::FileBase final
{
public:
	friend class CSVXX::DataFrame;

	platform::fileHandle 				_hFile;
	platform::fileHandle 				_hFileMap;
	std::size_t 						_fileSize;

	std::filesystem::path				_filePath;
	std::filesystem::path				_fileName;

	const std::byte*					_data;

public:
	explicit FileBase(  std::filesystem::path& filePath );
	~FileBase();

};


#endif
