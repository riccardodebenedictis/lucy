cmake_minimum_required(VERSION 3.7)

project ( lucy VERSION 0.1 LANGUAGES CXX )

find_package( Java )
find_package( JNI )

if( Java_FOUND )
  include( UseJava )
  file( GLOB GUI_SOURCES "gui/*.java" )
  add_jar( lucy_gui ${GUI_SOURCES} )

  file( GLOB SOURCES main.cpp "smt-lib/*.cpp" "core-lib/*.cpp" "cg-lib/*.cpp" "gui/*.cpp" )
  include_directories( ${CMAKE_SOURCE_DIR}/smt-lib ${CMAKE_SOURCE_DIR}/core-lib ${CMAKE_SOURCE_DIR}/cg-lib ${CMAKE_SOURCE_DIR}/gui ${JNI_INCLUDE_DIRS} )
else()
  file( GLOB SOURCES main.cpp "smt-lib/*.cpp" "core-lib/*.cpp" "cg-lib/*.cpp" )
  include_directories( ${CMAKE_SOURCE_DIR}/smt-lib ${CMAKE_SOURCE_DIR}/core-lib ${CMAKE_SOURCE_DIR}/cg-lib )
endif()

configure_file(cg-lib/init.rddl ${CMAKE_BINARY_DIR}/init.rddl COPYONLY)

add_executable( lucy ${SOURCES} )

if( Java_FOUND )
  target_link_libraries( lucy ${JNI_LIBRARIES} )
endif()

enable_testing()
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
