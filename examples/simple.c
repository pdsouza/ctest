#include "../src/ctest.h"

static int test_success() {
    ASSERT_EQ(0, 0);
}

static int test_failure() {
    ASSERT_EQ(0, 1);
}

int main () {
    struct TestRunner r = { 0 };
    TestRunner_init(&r);

    r.add(&r, test_success);
    r.add(&r, test_failure);

    return r.run(&r);
}
