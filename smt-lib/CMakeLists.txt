cmake_minimum_required(VERSION 3.7)

project ( smt-lib )

add_definitions(-DBUILDING_DLL)

file( GLOB SOURCES "*.cpp" )

add_library( smt-lib SHARED ${SOURCES} )

if( WIN32 )
  install( TARGETS smt-lib DESTINATION "C:/Program Files (x86)/smt-lib" )
endif()

if( UNIX )
  install( TARGETS smt-lib DESTINATION /usr/lib )
endif()