# Versao do Cmake que sera utilizada
cmake_minimum_required(VERSION 3.10)

# Nome do projeto
set(PROJECT_NAME "LaggandoGame")
project(${PROJECT_NAME})

# Adiciona a flag de debug
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Criando a lista de flags para o compilador
list(APPEND FLAGS "-std=c++11") # C++11
list(APPEND FLAGS "-Wall")      # Warnings
list(APPEND FLAGS "-Wextra")    # Warnings extras
list(JOIN FLAGS " " FLAGS)

# Adiciona flags de compilação para o projeto
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${FLAGS}")

# Adiciona o diretório src com os arquivos fonte do projeto
file(GLOB SRC_FILES CONFIGURE_DEPENDS "src/*.h" "src/*.cpp")

# Adiciona o cmake_modules para encontrar as bibliotecas necessárias no linux
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/arquivos/cmake_modules" ${CMAKE_MODULE_PATH})

# Adiciona a biblioteca -lpthread
set(THREADS "-lpthread")

# Adiciona os arquivos fonte ao projeto, e cria um executável
add_executable(${PROJECT_NAME} ${SRC_FILES})

# Adiciona a biblioteca SFML
find_package(SFML 2 REQUIRED system graphics window)

# Adiciona a biblioteca Threads
find_package(Threads REQUIRED)

# Testa se a biblioteca SFML foi encontrada
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})
endif ()
