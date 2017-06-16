cmake_minimum_required(VERSION 3.7)

project ( core-lib )

add_definitions(-DBUILDING_DLL)

include_directories( ${CMAKE_SOURCE_DIR}/smt-lib )

file( GLOB SOURCES "*.cpp" )

add_library( core-lib SHARED ${SOURCES} )

target_link_libraries( core-lib smt-lib )

if( WIN32 )
  target_link_libraries( core-lib )
  install( TARGETS core-lib DESTINATION "C:/Program Files (x86)/core-lib" )
endif()

if( UNIX )
  target_link_libraries( core-lib )
  install( TARGETS core-lib DESTINATION /usr/lib )
endif()