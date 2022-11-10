# Version of Cmake to use
cmake_minimum_required(VERSION 3.10)

# Project name
set(PROJECT_NAME "LaggandoGame")
project(${PROJECT_NAME})

# Set the compile commands on, used for debugging in case of errors
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Criando a lista de flags para o compilador
list(APPEND FLAGS "-std=c++11")
list(APPEND FLAGS "-Wall")
list(APPEND FLAGS "-Wextra")
list(APPEND FLAGS "-O3")
list(JOIN FLAGS " " FLAGS)

# Adiciona flags de compilação para o projeto
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${FLAGS}")

# Set files to compile, not recomended for production
file(GLOB SRC_FILES CONFIGURE_DEPENDS "src/*.h" "src/*.cpp")

# Set the file to locate the sfml library
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})

# Find the sfml library
set(THREADS "-lpthread")

# Set the source files to compile
add_executable(${PROJECT_NAME} ${SRC_FILES})

# Set the dependencies for the game
find_package(SFML 2 REQUIRED system graphics window network audio)
find_package(Threads REQUIRED)

# if sfml is not found, exit the build
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})
endif ()
