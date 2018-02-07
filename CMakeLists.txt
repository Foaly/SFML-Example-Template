cmake_minimum_required(VERSION 3.1)
set(PROJECT_NAME "SFMLExample")
project(${PROJECT_NAME})

message(STATUS "Configuring in ${CMAKE_BUILD_TYPE} mode.")

# enable C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# fix for OSX compilation
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -stdlib=libc++")

# define sources
set(EXECUTABLE_NAME "${PROJECT_NAME}")
set(SOURCE_FILES main.cpp)

# when we are on MacOS create a bundle and
# put the rescources in it
if(APPLE)
    add_executable(${EXECUTABLE_NAME} MACOSX_BUNDLE ${SOURCE_FILES})
    #target_link_libraries( ${EXECUTABLE_NAME} "-framework Foundation" )
else()
    add_executable(${EXECUTABLE_NAME} ${SOURCE_FILES})
endif()

# Add our CMake script
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})

# Detect and add any version 2.X of SFML
# See the FindSFML.cmake file for additional details and instructions
find_package(SFML 2 COMPONENTS system window graphics network audio REQUIRED)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})
else()
    message(FATAL_ERROR "Unable to find SFML!")
endif()
