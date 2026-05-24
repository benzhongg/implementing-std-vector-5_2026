#include "vector.h"
#include <gtest/gtest.h>
#include <stdexcept>

TEST(HelloWorldTest, BasicAssertions) {
    EXPECT_STRNE("hello", "world");
    EXPECT_EQ(6 * 6, 36);
}

TEST(SizeTest, SizeMatchesPushBackedValues) {
    CustomVector<int> vector1;
    vector1.pushBack(1);
    vector1.pushBack(2);

    ASSERT_EQ(vector1.size(), std::size_t{2});
}

TEST(ReadTest, OverloadedAccessOperatorReturnsCorrectValueAtIndex){
    CustomVector<int> vector1;
    vector1.pushBack(1);
    ASSERT_EQ(vector1[0], 1);
}

TEST(WriteTest, OverloadedAccessOperatorWritesCorrectValueAtIndex){
    CustomVector<int> vector1;
    vector1.pushBack(1);
    vector1[0] = 2;
    ASSERT_EQ(vector1[0], 2);
}

TEST(OutOfBoundsTestAccessOp, CorrectErrorOnInvalidIndex){
    CustomVector<int> vector1;
    EXPECT_THROW(vector1[1], std::out_of_range);
}

TEST(OutOfBoundsTestRemoveMethod, CorrectErrorOnInvalidIndex){
    CustomVector<int> vector1;
    EXPECT_THROW(vector1.remove(1), std::out_of_range);
}

//add item
//remove
TEST(ConsistentSizeTest, CheckSizeAfterRemovingItem){
    CustomVector<int> vector1;
    vector1.pushBack(1);
    ASSERT_EQ(vector1.size(), 1);
    vector1.remove(0);
    ASSERT_EQ(vector1.size(), 0);
}


// Below is a custom defined test suite.

// // ── Minimal test harness ──────────────────────────────────────────────────────
// static int g_pass = 0, g_fail = 0;

// #define TEST(name) void name();
// struct Reg##name { Reg##name() {
// try { name();
// printf(" \033[32m[PASS]\033[0m " #name "\n");
// ++g_pass;
// } catch (const std::exception& e) {
// printf(" \033[31m[FAIL]\033[0m " #name " → %s\n", e.what());
// ++g_fail;
// }
// catch(...) {
// printf(" \033[31m[FAIL]\033[0m " #name " → unknown exception\n");
// ++g_fail;
// }
// }} reg##name;
// void name()

// #define ASSERT_TRUE(expr)
// if (!(expr)) throw std::runtime_error("ASSERT_TRUE failed: " #expr)
// #define ASSERT_EQ(a, b)