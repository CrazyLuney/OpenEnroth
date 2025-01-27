cmake_minimum_required(VERSION 3.20.4 FATAL_ERROR)
project("OpenEnroth")

macro(target_precompile_headers_stl _TARGET)
    target_precompile_headers(${_TARGET} PRIVATE
        <algorithm>
        <any>
        <array>
        <atomic>
        <cassert>
        <cerrno>
        <cfloat>
        <charconv>
        <chrono>
        <climits>
        <cmath>
        <compare>
        <condition_variable>
        <cstdarg>
        <cstddef>
        <cstdlib>
        <cstdint>
        <cstdio>
        <ctime>
        <exception>
        <filesystem>
        <fstream>
        <functional>
        <initializer_list>
        <iostream>
        <iterator>
        <limits>
        <list>
        <map>
        <memory>
        <mutex>
        <numeric>
        <queue>
        <random>
        <ranges>
        <regex>
        <span>
        <sstream>
        <stdexcept>
        <string>
        <string_view>
        <system_error>
        <thread>
        <tuple>
        <type_traits>
        <typeindex>
        <unordered_map>
        <unordered_set>
        <utility>
        <variant>
        <vector>
        <version>
        <xutility>
        )

    if(MSVC)
        target_compile_options(${_TARGET} PRIVATE
            "/FI$<TARGET_PROPERTY:BINARY_DIR>/CMakeFiles/$<TARGET_PROPERTY:NAME>.dir/$<CONFIG>/cmake_pch.hxx")
    endif()
endmacro()

macro(target_precompile_headers_reuse _TARGET _FROM_TARGET)
    target_precompile_headers(${_TARGET} REUSE_FROM ${_FROM_TARGET})

    if(MSVC)
        target_compile_options(${_TARGET} PRIVATE
            "/FI$<TARGET_PROPERTY:${_FROM_TARGET},BINARY_DIR>/CMakeFiles/$<TARGET_PROPERTY:${_FROM_TARGET},NAME>.dir/$<CONFIG>/cmake_pch.hxx")
    endif()
endmacro()

add_compile_definitions(PACKAGE_BUGREPORT="https://github.com/OpenEnroth/OpenEnroth/issues")

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/CMakeModules)
include(Git)
include(Detection)

set(ENABLE_TESTS OFF CACHE BOOL "Enable tests")
#TODO: prebuilts should be available for all platforms and not just MSVC compiler
if(BUILD_COMPILER STREQUAL "msvc")
    set(PREBUILT_DEPENDENCIES ON CACHE BOOL "Use prebuilt dependencies")
else()
    set(PREBUILT_DEPENDENCIES OFF CACHE BOOL "Use prebuilt dependencies")
endif()

include(AppleLibcxxAssertions)
include(ExternalProject)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(ENABLE_TESTS)
  message(STATUS "Tests have been enabled")
endif()

if(BUILD_COMPILER STREQUAL "gcc")
    add_compile_definitions($<$<CONFIG:Debug>:_GLIBCXX_ASSERTIONS>)
    set(CMAKE_EXE_LINKER_FLAGS "-fuse-ld=gold -pthread")
elseif(BUILD_COMPILER STREQUAL "msvc")
    add_compile_definitions(NOMINMAX) # please don't pull in these macros from <Windows.h>
    add_compile_definitions(_CRT_SECURE_NO_WARNINGS) # STL security warnings are just noise
    add_compile_definitions(_CRT_NONSTDC_NO_DEPRECATE) # POSIX deprecation warnings are also just noise
    add_compile_definitions(_USE_MATH_DEFINES) # Pull in M_PI and other <cmath> defines
    add_compile_definitions(FMT_CONSTEVAL=) # MSVC chokes on fmt consteval formatting, so we define FMT_CONSTEVAL=<empty>
    add_compile_options(/Zc:preprocessor) # Use standard compliant preprocessor
    set(CMAKE_CXX_FLAGS "/MP ${CMAKE_CXX_FLAGS}")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /SAFESEH:NO")
elseif(BUILD_PLATFORM STREQUAL "darwin")
    enable_libcxx_assertions(FALSE)
endif()

if(BUILD_COMPILER STREQUAL "msvc")
    add_compile_options(/we4834) # Discarding return value of function with 'nodiscard' attribute
else() # gcc or clang
    add_compile_options(-Werror=return-type) # Control reaches the end of non-void function, this is an error on MSVC
    add_compile_options(-Werror=unused-result) # Ignoring return value of function declared with 'nodiscard' attribute
endif()

add_compile_definitions(FMT_USE_NONTYPE_TEMPLATE_ARGS) # Enable _cf literals

include(CppLint)
include(Dependencies)

add_subdirectory(thirdparty)

include_directories(${INCLUDE_DIRECTORIES} ${CMAKE_CURRENT_SOURCE_DIR}/src ${CMAKE_CURRENT_SOURCE_DIR}/test ${INCLUDE_THIRDPARTY_DIRS})
add_subdirectory(test)
add_subdirectory(src)

if(BUILD_PLATFORM STREQUAL "android")
    add_library(main SHARED)
    target_sources(main PUBLIC src/Application/main.cpp src/Platform/Sdl/SdlMain.cpp)
    target_link_libraries(main application utility)
    target_precompile_headers_reuse(main utility)
else()
    add_executable(OpenEnroth MACOSX_BUNDLE WIN32 src/Application/main.cpp)
    target_fix_libcxx_assertions(OpenEnroth)

    target_link_libraries(OpenEnroth application utility)
    target_precompile_headers_reuse(OpenEnroth utility)

    set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT OpenEnroth)

    PREBUILT_DEPENDENCIES_RESOLVE(OpenEnroth)
endif()
