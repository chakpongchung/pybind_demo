cmake_minimum_required(VERSION 3.1)
project(pybind_demo)

set(CMAKE_CXX_STANDARD 11)
set(LIB_GEN_PATH ${PROJECT_SOURCE_DIR}/scripts CACHE STRING "Where generated library will be placed")

find_package(PythonLibs 3 REQUIRED)

add_subdirectory(pybind11)
pybind11_add_module(pybind_demo src/pybind_demo.cpp)
target_include_directories(pybind_demo PRIVATE ${PYTHON_INCLUDE_DIRS})
set_target_properties(pybind_demo
    PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY ${LIB_GEN_PATH}
)
set_source_files_properties(src/pybind_demo.cpp 
    PROPERTIES COMPILE_FLAGS -Wall -Wextra -Weffc++ -pedantic -Werror
)
