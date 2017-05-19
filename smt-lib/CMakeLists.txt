cmake_minimum_required(VERSION 3.0)

project ( smt-lib )

file( GLOB SOURCES "*.cpp" )

add_library( smt-lib SHARED ${SOURCES} )

if( WIN32 )
  install( TARGETS smt-lib DESTINATION "C:/Program Files (x86)/lucy" )
endif()

if( UNIX )
  install( TARGETS smt-lib DESTINATION /usr/lib )
endif()