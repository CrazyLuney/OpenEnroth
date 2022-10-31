set(PROJECT_VERSION "unknown")

find_package(Git)

if(GIT_FOUND)
  execute_process(COMMAND ${GIT_EXECUTABLE} describe --always --tags --dirty
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    OUTPUT_VARIABLE GIT_VERSION
    OUTPUT_STRIP_TRAILING_WHITESPACE)

  if(NOT "${GIT_VERSION}" STREQUAL "")
    set(PROJECT_VERSION ${GIT_VERSION})
  endif()

  execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    OUTPUT_VARIABLE WOMM_VERSION
    OUTPUT_STRIP_TRAILING_WHITESPACE)
endif()

message(STATUS "WoMM version: ${PROJECT_VERSION}")
