include_directories( ${CMAKE_SOURCE_DIR}/smt-lib )

add_executable( test_smt test_smt.cpp )

target_link_libraries( test_smt smt-lib )

add_test( TestSMT ${CMAKE_BINARY_DIR}/dist/test_smt )