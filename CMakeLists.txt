cmake_minimum_required(VERSION 3.15)

project(visitor_calculator)


add_executable(calculator src/main.cpp)
target_compile_features(calculator
    PRIVATE
        cxx_std_17
)


target_link_libraries(calculator PRIVATE fc)
# target_include_directories(calculator PRVATE ${fc_headers})

add_subdirectory(ext/hive)
