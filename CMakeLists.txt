cmake_minimum_required(VERSION 2.8.7)

# find YARP
find_package(YARP REQUIRED)

# add YARP include directories
include_directories(${YARP_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# set up our program
add_executable(currentFixationPointRead currentFixationPointRead.cpp)
add_executable(targetPointSend targetPointSend.cpp)
add_executable(readAndWriteTopicsTest ReadAndWriteTopicsTest.cpp)
add_executable(readAndWriteTopicsTestSwap ReadAndWriteTopicsTestSwap.cpp)

# link with YARP libraries
target_link_libraries(currentFixationPointRead ${YARP_LIBRARIES})
target_link_libraries(targetPointSend ${YARP_LIBRARIES})
target_link_libraries(readAndWriteTopicsTest ${YARP_LIBRARIES})
target_link_libraries(readAndWriteTopicsTestSwap ${YARP_LIBRARIES})
