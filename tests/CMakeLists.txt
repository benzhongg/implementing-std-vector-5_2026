include(CompilerWarnings)

add_executable(engine_tests test.cpp)

target_link_libraries(engine_tests PRIVATE engine)
target_enable_warnings(engine_tests)

enable_testing()
add_test(NAME engine_tests COMMAND engine_tests)