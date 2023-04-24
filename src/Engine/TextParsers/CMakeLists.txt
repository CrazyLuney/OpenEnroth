cmake_minimum_required(VERSION 3.20.4 FATAL_ERROR)

set(ENGINE_TEXT_PARSERS_SOURCES
        TextParsersDummy.cpp)

set(ENGINE_TEXT_PARSERS_HEADERS
        MonsterInfoParser/MonsterInfoParser.hpp)

add_library(engine_text_parsers STATIC ${ENGINE_TEXT_PARSERS_SOURCES} ${ENGINE_TEXT_PARSERS_HEADERS})

target_link_libraries(engine_text_parsers
        engine_objects
        engine_serialization
        engine_spells
        engine_tables
        library_compression
        library_logger
        library_serialization
        utility)

target_include_directories(engine_text_parsers
        PRIVATE
                "${CMAKE_CURRENT_SOURCE_DIR}"
        PUBLIC
                "${CMAKE_CURRENT_SOURCE_DIR}")

target_precompile_headers_reuse(engine_text_parsers utility)
