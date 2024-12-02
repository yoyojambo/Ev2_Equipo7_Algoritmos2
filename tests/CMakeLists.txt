include(FetchContent)

# Fetch Catch2
FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG v3.4.0 # Use the latest stable version
)
FetchContent_MakeAvailable(Catch2)

# Add the test executable
add_executable(tests test_main.cpp)

# Link the test executable to the libraries and Catch2
target_link_libraries(tests PRIVATE ford_fulkerson kruskal tsp Catch2::Catch2WithMain)

# Enable testing
enable_testing()
add_test(NAME GraphAlgorithmsTests COMMAND tests)
