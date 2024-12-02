cmake_minimum_required(VERSION 3.15)

project(GraphAlgorithms VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    # Add coverage flags for GCC/Clang
    add_compile_options(-g -O0 --coverage -fprofile-arcs -ftest-coverage)
    add_link_options(--coverage -lgcov)
endif()

# Include subdirectories
add_subdirectory(src)
add_subdirectory(tests)
add_subdirectory(app)

# # Add the main executable
# add_executable(main main.cpp)
# target_link_libraries(main PRIVATE ford_fulkerson kruskal tsp lineal)

