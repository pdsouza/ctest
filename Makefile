CFLAGS  += -Wall
LDFLAGS += -Lsrc

MODULE := ctest
TARGET := src/lib$(MODULE).a
SRCS   := $(wildcard src/*.c)
OBJS   := $(patsubst %.c,%.o,$(SRCS))
LIBS   += -l$(MODULE)

TEST_MODULE := testsuite
TEST_TARGET := tests/$(TEST_MODULE)
TEST_SRCS   := $(wildcard tests/*.c)
TEST_OBJS   := $(patsubst %.c,%.o,$(TEST_SRCS))

.PHONY: all test clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(AR) rc $@ $^

test: $(TEST_TARGET)
	./$(TEST_TARGET)

$(TEST_TARGET): $(TEST_OBJS) $(TARGET)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $(TEST_OBJS) $(LIBS)

clean:
	-rm $(OBJS) $(TEST_OBJS)
	-rm $(TARGET) $(TEST_TARGET)
