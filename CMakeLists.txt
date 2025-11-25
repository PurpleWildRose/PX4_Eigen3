cmake_minimum_required(VERSION 3.1.0)
project(Eigen_5.0.1)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/Modules")

include(Eigen3)

set(EXAMPLE_DIR "src/examples")
add_executable(${PROJECT_NAME} ${EXAMPLE_DIR}/2/6.cpp)
