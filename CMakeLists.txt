cmake_minimum_required(VERSION 3.15)

project(visitor_calculator)


add_library(visitor INTERFACE)
target_include_directories(visitor INTERFACE src)
target_link_libraries(visitor INTERFACE fc)
target_compile_features(visitor
    INTERFACE
        cxx_std_17
)

add_executable(calculator src/main.cpp)
target_link_libraries(calculator PRIVATE visitor argparse::argparse)


add_subdirectory(ext/hive)
add_subdirectory(ext/argparse)
add_subdirectory(tests)