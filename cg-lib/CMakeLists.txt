cmake_minimum_required(VERSION 3.7)

project ( cg-lib )

add_definitions(-DBUILDING_DLL)

file( GLOB SOURCES "*.cpp" )

configure_file(init.rddl ${CMAKE_BINARY_DIR}/init.rddl COPYONLY)

add_library( cg-lib SHARED ${SOURCES} )

include_directories( ${CMAKE_SOURCE_DIR}/smt-lib ${CMAKE_SOURCE_DIR}/core-lib )
target_link_libraries( cg-lib core-lib )

if( Java_FOUND )
  include_directories( ${JNI_INCLUDE_DIRS} )
  target_link_libraries( cg-lib ${JNI_LIBRARIES} )
endif()

if( WIN32 )
  install( TARGETS cg-lib DESTINATION "C:/Program Files (x86)/cg-lib" )
endif()

if( UNIX )
  install( TARGETS cg-lib DESTINATION /usr/lib )
endif()