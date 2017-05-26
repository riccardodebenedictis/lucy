include_directories( ${CMAKE_SOURCE_DIR}/smt-lib )

add_executable( test_smt test_smt.cpp )

target_link_libraries( test_smt smt-lib )

add_test( NAME TestSMT COMMAND test_smt )