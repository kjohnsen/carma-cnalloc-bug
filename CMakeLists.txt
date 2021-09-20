project(pybind-arma-bug LANGUAGES CXX)
cmake_minimum_required(VERSION 3.16 FATAL_ERROR)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
if (WIN32)
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
endif()

add_library(mc SHARED mat_container.cpp)

find_package(Armadillo "10.6" CONFIG REQUIRED)

find_package(Python3 REQUIRED COMPONENTS Interpreter Development NumPy)
add_subdirectory(pybind11)
add_subdirectory(carma)
pybind11_add_module(pymod MODULE pymod.cpp)

include_directories(${ARMADILLO_INCLUDE_DIRS} ${Python3_NumPy_INCLUDE_DIRS}) 
target_link_libraries(mc PUBLIC ${ARMADILLO_LIBARIES})
target_compile_definitions(pymod PUBLIC ARMA_EXTRA_DEBUG CARMA_EXTRA_DEBUG)
# simply linking to carma::carma, whether or not carma is included, changes the Armadillo config
# the way to avoid this is to include only carma::headers
target_link_libraries(pymod PUBLIC mc carma::headers)

FILE(TOUCH "${PROJECT_BINARY_DIR}/__init__.py")