cmake_minimum_required(VERSION 3.7)

project ( cg-lib )

add_definitions(-DBUILDING_DLL)

find_package(VTK 8.0 REQUIRED NO_MODULE)
include(${VTK_USE_FILE})

if( WIN32 )
  include_directories( "C:/Program Files (x86)/LIBANTLR4/include/antlr4-runtime" )
  link_directories( "C:/Program Files (x86)/LIBANTLR4/lib" )
endif()

if( UNIX )
  include_directories( /usr/local/include/antlr4-runtime )
  link_directories( /usr/local/lib )
endif()

include_directories( ${CMAKE_SOURCE_DIR}/smt-lib ${CMAKE_SOURCE_DIR}/core-lib )

file( GLOB SOURCES "*.cpp" )

configure_file(init.rddl ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/init.rddl COPYONLY)

add_library( cg-lib SHARED ${SOURCES} )

target_link_libraries( cg-lib core-lib ${VTK_LIBRARIES} )

if( WIN32 )
  install( TARGETS cg-lib DESTINATION "C:/Program Files (x86)/cg-lib" )
endif()

if( UNIX )
  install( TARGETS cg-lib DESTINATION /usr/lib )
endif()