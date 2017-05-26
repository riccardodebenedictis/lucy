include_directories( ${CMAKE_SOURCE_DIR}/smt-lib ${CMAKE_SOURCE_DIR}/core-lib ${CMAKE_SOURCE_DIR}/cg-lib )

add_executable( test_cg test_cg.cpp )

target_link_libraries( test_cg cg-lib )

add_test( NAME Test_CG_0 COMMAND test_cg )