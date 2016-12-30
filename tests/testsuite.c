/*
 * Copyright 2016 Preetam D'Souza
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <stdio.h>
#include <stdint.h>
#include <assert.h>

#include "../src/ctest.h"

/**
 * Sadly, we can't use ctest because bugs in ctest would affect ctest's
 * tests! We use simple asserts instead.
 */

static int test_success() {
    ASSERT_EQ(0, 0);
}

static int test_failure() {
    ASSERT_EQ(0, 1);
}

static int test_run(struct TestRunner *r) {
    int res = -1;

    printf("# ----------------------------------------------------------\n");
    res = r->run(r);
    printf("# ----------------------------------------------------------\n");
    printf("\n");

    return res;
}

static void test_add() {
    struct TestRunner r = { 0 };
    TestRunner_init(&r);

    int res;
    res = r.add(&r, test_success);
    assert(0 == res);
    res = r.add(&r, test_failure);
    assert(0 == res);

    assert(2 == r.mNumTests);
}

static void test_report_success() {
    struct TestRunner r = { 0 };
    TestRunner_init(&r);

    r.add(&r, test_success);

    assert(0 == test_run(&r));
}

static void test_report_failure() {
    struct TestRunner r = { 0 };
    TestRunner_init(&r);

    r.add(&r, test_success);
    r.add(&r, test_failure);

    assert(0 > test_run(&r));
}

int main() {
    test_add();
    test_report_success();
    test_report_failure();

    printf("All tests passed.\n");
    return 0;
}
