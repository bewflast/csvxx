
#ifndef CSVXX_PLATFORM_HPP
# define CSVXX_PLATFORM_HPP

# include <system_error>

#ifdef _WINDOWS
# include "FileBase/platformDefines/windows.hpp"
# define GET_SYSTEM_ERROR_NUM static_cast<int>(GetLastError())
#else
# include "FileBase/platformDefines/linux.hpp"
# define GET_SYSTEM_ERROR_NUM static_cast<int>(errno)
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
