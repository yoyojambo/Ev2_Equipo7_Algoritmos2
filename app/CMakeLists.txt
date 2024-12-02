# Add an executable for the app
add_executable(main main.cpp)

# Link the app executable to the libraries in src
target_link_libraries(main PRIVATE ford_fulkerson kruskal tsp lineal)
