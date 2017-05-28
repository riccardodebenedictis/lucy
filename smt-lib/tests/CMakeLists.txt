include_directories( ${CMAKE_SOURCE_DIR}/smt-lib )

add_executable( test_sat_0 test_sat_0.cpp )
add_executable( test_la_0 test_la_0.cpp )
add_executable( test_la_1 test_la_1.cpp )
add_executable( test_la_2 test_la_2.cpp )
add_executable( test_la_prop test_la_prop.cpp )

target_link_libraries( test_sat_0 smt-lib )
target_link_libraries( test_la_0 smt-lib )
target_link_libraries( test_la_1 smt-lib )
target_link_libraries( test_la_2 smt-lib )
target_link_libraries( test_la_prop smt-lib )

add_test( NAME TestSAT0 COMMAND test_sat_0 WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/smt-lib )
add_test( NAME TestLA0 COMMAND test_la_0 WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/smt-lib )
add_test( NAME TestLA1 COMMAND test_la_1 WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/smt-lib )
add_test( NAME TestLA2 COMMAND test_la_2 WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/smt-lib )
add_test( NAME TestLAPropagation COMMAND test_la_prop WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/smt-lib )