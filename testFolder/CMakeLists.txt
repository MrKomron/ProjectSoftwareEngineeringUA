cmake_minimum_required(VERSION 3.26)
project(testFolder)

set(CMAKE_CXX_STANDARD 17)

# Set include dir
include_directories(./gtest/include)
include_directories(./XMLREADER)
# Set Library dir
link_directories(./gtest/lib)

# Add executable and link against TinyXML library
add_executable(testFolder main.cpp Job.cpp Device.cpp StatusReport.cpp XMLREADER/XMLReader.cpp XMLREADER/tinystr.cpp XMLREADER/tinyxml.cpp XMLREADER/tinyxmlerror.cpp XMLREADER/tinyxmlparser.cpp
        Device.cpp
        StatusReport.cpp
        StatusReport.h
        SystemProcessing.cpp
        SystemProcessing.h
)
