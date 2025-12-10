cmake_minimum_required(VERSION 3.1.0)
project(Eigen_5.0.1)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/Modules")

include(Eigen3)

# 禁用 Eigen SIMD 优化（解决 __vector 类型属性警告）
add_definitions(-DEIGEN_DONT_VECTORIZE)
# 可选：禁用未对齐数组断言（进一步避免兼容性问题）
add_definitions(-DEIGEN_DISABLE_UNALIGNED_ARRAY_ASSERT)


set(EXAMPLE_DIR "src/examples")
add_executable(${PROJECT_NAME} ${EXAMPLE_DIR}/7/9.cpp)
# 针对 GCC 编译器，抑制 -Wignored-attributes 警告
target_compile_options(${PROJECT_NAME} PRIVATE -Wno-ignored-attributes -Wno-deprecated-declarations)

