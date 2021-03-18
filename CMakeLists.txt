cmake_minimum_required(VERSION 3.1)

project(socketcpp VERSION 0.0.1 DESCRIPTION "Linux Socket C++11 Wrapper" LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED 11)
set(CMAKE_CXX_EXTENSIONS OFF)

add_compile_options(-Wall -Wextra)

# Conan packages
# -----------------------------------------
include(${CMAKE_BINARY_DIR}/conan_paths.cmake)
# -----------------------------------------

# CMake helpers
# -----------------------------------------
list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
# -----------------------------------------

# Dependencies
# -----------------------------------------
find_package(doctest REQUIRED)
# -----------------------------------------

# Subprojects
# -----------------------------------------
# add_subdirectory(deps/sqlite3)
# -----------------------------------------

# Monkey-Patching Test
# -----------------------------------------
# add_library(datefaker SHARED src/datefaker.cpp)
# target_include_directories(datefaker PUBLIC src)
# -----------------------------------------

# CMake Configured header
# -----------------------------------------
configure_file(src/cmake_variables.hpp.in cmake_variables.hpp)
# -----------------------------------------

set(SOURCE_FILES src/main.cpp src/calc.cpp)

add_executable(main ${SOURCE_FILES})
target_include_directories(main PRIVATE ${CMAKE_SOURCE_DIR} ${CMAKE_BINARY_DIR})
target_compile_definitions(main PRIVATE DOCTEST_CONFIG_DISABLE)
target_link_libraries(main PRIVATE doctest::doctest)

add_executable(tests ${SOURCE_FILES})
target_include_directories(tests PRIVATE ${CMAKE_SOURCE_DIR} ${CMAKE_BINARY_DIR})
target_link_libraries(tests PRIVATE doctest::doctest)
