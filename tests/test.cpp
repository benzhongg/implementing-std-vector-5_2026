#include "vector.h"


// ── Minimal test harness ──────────────────────────────────────────────────────
static int g_pass = 0, g_fail = 0;

#define TEST(name) void name();
struct Reg##name { Reg##name() {
try { name();
printf(" \033[32m[PASS]\033[0m " #name "\n");
++g_pass;
} catch (const std::exception& e) {
printf(" \033[31m[FAIL]\033[0m " #name " → %s\n", e.what());
++g_fail;
}
catch(...) {
printf(" \033[31m[FAIL]\033[0m " #name " → unknown exception\n");
++g_fail;
}
}} reg##name;
void name()

#define ASSERT_TRUE(expr)
if (!(expr)) throw std::runtime_error("ASSERT_TRUE failed: " #expr)
#define ASSERT_EQ(a, b)

// ==============================================================
// these are test cases below

TEST(insert_and_get) {
CustomVector vector1;
vector1.pushBack(1);
vector1.pushBack(2);

ASSERT_EQ(vector1.size(), std::size_t{2});
}

//

