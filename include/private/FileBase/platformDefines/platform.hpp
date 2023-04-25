
#ifndef CSVXX_PLATFORM_HPP
# define CSVXX_PLATFORM_HPP

# include <system_error>

#ifdef _WINDOWS
# include "FileBase/platformDefines/windows.hpp"
#else
# include "FileBase/platformDefines/linux.hpp"
#endif

namespace CSVXX
{
	struct SystemException: std::system_error
	{
		explicit SystemException(const char* message):
			std::system_error(GET_SYSTEM_ERROR_NUM, std::generic_category(), message)
		{};
	};
}

#endif //CSVXX_PLATFORM_HPP
