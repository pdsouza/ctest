# ctest
[![Build Status](https://travis-ci.org/pdsouza/ctest.svg?branch=master)](https://travis-ci.org/pdsouza/ctest)

Simple testing library for C.

## Examples

simple.c:

```C
#include "ctest.h"

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
```

Output:

```
$ ./simple 
test_success                  [ PASS ]
test_failure                  [ FAIL ] (0 != 1)

1 of 2 test cases passed.
```

See [examples](examples) for more.
