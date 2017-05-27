cmake_minimum_required(VERSION 3.7)

project ( lucy VERSION 0.1 LANGUAGES CXX )

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

add_test( NAME TestCG0 COMMAND lucy WORKING_DIRECTORY ${CMAKE_BINARY_DIR} )
add_test( NAME TestCG1 COMMAND lucy "${CMAKE_SOURCE_DIR}/examples/example_0.rddl" "solution.json" WORKING_DIRECTORY ${CMAKE_BINARY_DIR} )
if( WIN32 )
  set( PATH_STRING "$ENV{PATH};${CMAKE_BINARY_DIR}/smt-lib;${CMAKE_BINARY_DIR}/core-lib;${CMAKE_BINARY_DIR}/cg-lib;C:/Program Files (x86)/LIBANTLR4/lib" )
  string( REPLACE ";" "\\;" PATH_STRING "${PATH_STRING}" )
  set_tests_properties( TestCG0 TestCG1 PROPERTIES ENVIRONMENT "PATH=${PATH_STRING}" )
endif()
