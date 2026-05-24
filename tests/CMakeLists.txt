add_executable(vector_test test.cpp)

target_link_libraries(vector_test PRIVATE VECTOR GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(vector_test)




