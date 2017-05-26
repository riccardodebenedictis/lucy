include_directories( ${CMAKE_SOURCE_DIR}/smt-lib )

add_executable( sat_0 test_sat_0.cpp )
add_executable( la_0 test_la_0.cpp )
add_executable( la_1 test_la_1.cpp )
add_executable( theory_propagation test_theory_propagation.cpp )

target_link_libraries( sat_0 smt-lib )
target_link_libraries( la_0 smt-lib )
target_link_libraries( la_1 smt-lib )
target_link_libraries( theory_propagation smt-lib )