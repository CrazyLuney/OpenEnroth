cmake_minimum_required(VERSION 3.20.4 FATAL_ERROR)

set(LIBRARY_RANDOM_SOURCES
        Random.cpp
        RandomEngine.cpp)

set(LIBRARY_RANDOM_HEADERS
        MersenneTwisterRandomEngine.h
        NonRandomEngine.h
        Random.h
        RandomEngine.h)

add_library(library_random STATIC ${LIBRARY_RANDOM_SOURCES} ${LIBRARY_RANDOM_HEADERS})
target_link_libraries(library_random utility)

target_precompile_headers_reuse(library_random utility)
