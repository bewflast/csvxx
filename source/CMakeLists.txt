set(CMAKE_CXX_STANDARD 17)

if(${CMAKE_SYSTEM_NAME} MATCHES "Windows")
    set(PLATFORM_SOURCES ${CSVXX_SOURCES}/FileBase/platformDefines/windows.cpp)
else()
    set(PLATFORM_SOURCES ${CSVXX_SOURCES}/FileBase/platformDefines/linux.cpp)
endif()

set(SOURCES
        ${PLATFORM_SOURCES}
        ${CSVXX_SOURCES}/DataFrame.cpp
        #${CSVXX_SOURCES}/FileBase/FileBase.cpp
        ${CSVXX_SOURCES}/FileBase/File.cpp
        ${CSVXX_SOURCES}/FileBase/UniqueFileDescriptor.cpp
        ${CSVXX_SOURCES}/FileBase/MemoryMap.cpp)

target_include_directories(csvxx PRIVATE ${CSVXX_INCLUDES}/private)
target_sources(csvxx PRIVATE ${SOURCES})