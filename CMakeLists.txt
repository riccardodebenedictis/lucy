cmake_minimum_required(VERSION 3.7)

project ( lucy VERSION 0.1 LANGUAGES CXX )

enable_testing()
find_package( Java )

add_subdirectory( smt-lib )
add_subdirectory( core-lib )
add_subdirectory( cg-lib )

include_directories( ${CMAKE_SOURCE_DIR}/smt-lib ${CMAKE_SOURCE_DIR}/core-lib ${CMAKE_SOURCE_DIR}/cg-lib )

add_executable( lucy main.cpp )

target_link_libraries( lucy cg-lib core-lib smt-lib )

add_test( NAME TestCG COMMAND lucy WORKING_DIRECTORY ${CMAKE_BINARY_DIR} )
add_test( NAME TestCG0 COMMAND lucy "${CMAKE_SOURCE_DIR}/examples/example_0.rddl" "solution.json" WORKING_DIRECTORY ${CMAKE_BINARY_DIR} )
add_test( NAME TestCG1 COMMAND lucy "${CMAKE_SOURCE_DIR}/examples/example_1.rddl" "solution.json" WORKING_DIRECTORY ${CMAKE_BINARY_DIR} )
add_test( NAME TestSV0 COMMAND lucy "${CMAKE_SOURCE_DIR}/examples/test_sv_0.rddl" "solution.json" WORKING_DIRECTORY ${CMAKE_BINARY_DIR} )
add_test( NAME TestSV1 COMMAND lucy "${CMAKE_SOURCE_DIR}/examples/test_sv_1.rddl" "solution.json" WORKING_DIRECTORY ${CMAKE_BINARY_DIR} )
add_test( NAME TestSV2 COMMAND lucy "${CMAKE_SOURCE_DIR}/examples/test_sv_2.rddl" "solution.json" WORKING_DIRECTORY ${CMAKE_BINARY_DIR} )
add_test( NAME TestRR0 COMMAND lucy "${CMAKE_SOURCE_DIR}/examples/test_rr_0.rddl" "solution.json" WORKING_DIRECTORY ${CMAKE_BINARY_DIR} )
add_test( NAME TestRR1 COMMAND lucy "${CMAKE_SOURCE_DIR}/examples/test_rr_1.rddl" "solution.json" WORKING_DIRECTORY ${CMAKE_BINARY_DIR} )
add_test( NAME TestBlocks2 COMMAND lucy "${CMAKE_SOURCE_DIR}/examples/blocks_2.rddl" "solution.json" WORKING_DIRECTORY ${CMAKE_BINARY_DIR} )
add_test( NAME TestBlocks3 COMMAND lucy "${CMAKE_SOURCE_DIR}/examples/blocks_3.rddl" "solution.json" WORKING_DIRECTORY ${CMAKE_BINARY_DIR} )
add_test( NAME TestBlocks4 COMMAND lucy "${CMAKE_SOURCE_DIR}/examples/blocks_4.rddl" "solution.json" WORKING_DIRECTORY ${CMAKE_BINARY_DIR} )

if( WIN32 )
  set( PATH_STRING "$ENV{PATH};${CMAKE_BINARY_DIR}/smt-lib;${CMAKE_BINARY_DIR}/core-lib;${CMAKE_BINARY_DIR}/cg-lib" )
  string( REPLACE ";" "\\;" PATH_STRING "${PATH_STRING}" )
  set_tests_properties( TestCG TestCG0 TestCG1 TestSV0 TestSV1 TestSV2 TestRR0 TestRR1 TestBlocks2 TestBlocks3 TestBlocks4 PROPERTIES ENVIRONMENT "PATH=${PATH_STRING}" )
endif()
