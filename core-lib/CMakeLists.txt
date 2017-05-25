cmake_minimum_required(VERSION 3.7)

project ( core-lib )

add_definitions(-DBUILDING_DLL)

if( WIN32 )
  include_directories( "C:/Program Files (x86)/LIBANTLR4/include/antlr4-runtime" )
  link_directories( "C:/Program Files (x86)/LIBANTLR4/lib" )
endif()

if( UNIX )
  include_directories( /usr/local/include/antlr4-runtime )
  link_directories( /usr/local/lib )
endif()

include_directories( ${CMAKE_SOURCE_DIR}/smt-lib parser )

file( GLOB SOURCES "*.cpp" "parser/*.cpp" )

add_library( core-lib SHARED ${SOURCES} )

target_link_libraries( core-lib smt-lib )

if( WIN32 )
  target_link_libraries( core-lib antlr4-runtime.lib )
  install( TARGETS core-lib DESTINATION "C:/Program Files (x86)/core-lib" )
endif()

if( UNIX )
  target_link_libraries( core-lib libantlr4-runtime.so )
  install( TARGETS core-lib DESTINATION /usr/lib )
endif()