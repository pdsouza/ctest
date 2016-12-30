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

#ifndef __CTEST_H__
#define __CTEST_H__

#include <stdio.h>

#define TEST_PASS_TAG "[ PASS ]"
#define TEST_FAIL_TAG "[ FAIL ]"

#define MAX_NUM_TESTS (1 << 6)

#define ASSERT_EQ(expected, value) \
    if (expected != value) { \
        printf("%-30s" TEST_FAIL_TAG " (%d != %d)\n", __func__, expected, value); \
        return -1; \
    } \
    printf("%-30s" TEST_PASS_TAG "\n", __func__); \
    return 0;

typedef int (*TestCase)(void);
struct TestRunner {
    int mNumTests;
    int mNumPassed;
    TestCase mTestCases[MAX_NUM_TESTS];

    int (*add) (struct TestRunner *this, TestCase t);
    int (*run) (struct TestRunner *this);
};

void TestRunner_init(struct TestRunner *r);

#endif // __CTEST_H__
