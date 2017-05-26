cmake_minimum_required(VERSION 3.7)

project ( lucy VERSION 0.1 LANGUAGES CXX )

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/dist)

enable_testing()

add_subdirectory( smt-lib )
add_subdirectory( core-lib )
add_subdirectory( cg-lib )

if( WIN32 )
  include_directories( "C:/Program Files (x86)/LIBANTLR4/include/antlr4-runtime" )
  link_directories( "C:/Program Files (x86)/LIBANTLR4/lib" )
endif()

if( UNIX )
  include_directories( /usr/local/include/antlr4-runtime )
  link_directories( /usr/local/lib )
endif()

include_directories( ${CMAKE_SOURCE_DIR}/smt-lib ${CMAKE_SOURCE_DIR}/core-lib ${CMAKE_SOURCE_DIR}/cg-lib )

add_executable( lucy main.cpp )

target_link_libraries( lucy cg-lib core-lib smt-lib )