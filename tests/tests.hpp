
#ifndef CSVXX_TESTS_HPP
#define CSVXX_TESTS_HPP

# include <fstream>
# include <gtest/gtest.h>
# include <FileBase/File.hpp>
# include <FileBase/MemoryMap.hpp>
# include <FileBase/UniqueFileDescriptor.hpp>

#ifdef _WINDOWS
# define DATA_FILE(f) (("../data/" + std::string(f)).c_str())
#else
# define DATA_FILE(f) (("data/" + std::string(f)).c_str())
#endif

#endif //CSVXX_TESTS_HPP
