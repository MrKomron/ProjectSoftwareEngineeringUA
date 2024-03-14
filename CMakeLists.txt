cmake_minimum_required(VERSION 3.6)
project(ProjectSoftwareEngineeringUA)

set(CMAKE_VERBOSE_MAKEFILE ON)

set(CMAKE_CXX_STANDARD 17)
# Remove the "-O2" flag if you have problems with the debugger.
set(CMAKE_CXX_FLAGS "-std=c++17 -Wall -Werror -O2")
set(CMAKE_EXE_LINKER_FLAGS -pthread)

# Set include dir
include_directories(./gtest/include)

# Set Library dir
link_directories(./gtest/lib)

# Set source files for RELEASE target
# Only add cpp files, no h files!
# Only add files with functionality here, no test files!
set(RELEASE_SOURCE_FILES  src/main.cpp src/tinyxml.cpp src/tinystr.cpp src/tinyxml.cpp src/tinyxmlerror.cpp src/tinyxmlparser.cpp
        src/XMLParsingLogic.cpp
        src/XMLParsingLogic.h)

# Set source files for DEBUG target
# Only add cpp files, no h files!
set(DEBUG_SOURCE_FILES src/tests.cpp )

# Create RELEASE target
#add_executable(release_target ${RELEASE_SOURCE_FILES})

# Create DEBUG target
add_executable(debug_target
                            src/Tests.cpp
                            src/Job.cpp
                            src/Device.cpp
                            src/StatusReport.cpp
                            src/XMLREADER/XMLReader.cpp
                            src/XMLREADER/tinystr.cpp
                            src/XMLREADER/tinyxml.cpp
                            src/XMLREADER/tinyxmlerror.cpp
                            src/XMLREADER/tinyxmlparser.cpp
                            src/SystemProcessing.cpp
)

# Link library
target_link_libraries(debug_target gtest)
