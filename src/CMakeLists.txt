add_library(ford_fulkerson ford_fulkerson.cpp)
target_include_directories(ford_fulkerson PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_library(kruskal kruskal.cpp)
target_include_directories(kruskal PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_library(tsp tsp.cpp)
target_include_directories(tsp PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
