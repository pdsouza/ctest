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

#include "ctest.h"

static int add(struct TestRunner *this, TestCase t) {
    if (this->mNumTests + 1 > MAX_NUM_TESTS) {
        return -1;
    }

    this->mTestCases[this->mNumTests++] = t;
    return 0;
}

static int run(struct TestRunner *this) {
    int i;
    for (i = 0; i < this->mNumTests; ++i) {
        if (!this->mTestCases[i]()) {
            ++this->mNumPassed;
        }
    }

    printf("\n");
    printf("%d of %d test cases passed.\n", this->mNumPassed, this->mNumTests);
    return this->mNumPassed - this->mNumTests;
}

void TestRunner_init(struct TestRunner *r) {
    r->add = add;
    r->run = run;
}
