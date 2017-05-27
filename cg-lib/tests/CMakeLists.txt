include_directories( ${CMAKE_SOURCE_DIR}/smt-lib ${CMAKE_SOURCE_DIR}/core-lib ${CMAKE_SOURCE_DIR}/cg-lib )

add_executable( test_cg test_cg.cpp )

target_link_libraries( test_cg cg-lib )

add_test( NAME TestCG0 COMMAND test_cg WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY} )

if( WIN32 )
  set_tests_properties( TestCG0 PROPERTIES ENVIRONMENT "PATH=C:/Program Files (x86)/LIBANTLR4/lib;$ENV{PATH}" )
endif()