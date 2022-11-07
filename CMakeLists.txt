# Version of Cmake to use
cmake_minimum_required(VERSION 3.10)

# Project name
project(Game)

# Set the version of cpp to use
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# Set the compile commands on, used for debugging in case of errors
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Set files to compile, not recomended for production
file(GLOB SRC_FILES CONFIGURE_DEPENDS "sources/*.h" "sources/*.cpp")

# Set the file to locate the sfml library
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})

# Set the source files to compile
add_executable(Game ${SRC_FILES})

# Set the dependencies for the game
find_package(SFML 2 REQUIRED system graphics window network audio)

# if sfml is not found, exit the build
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES})
endif ()
