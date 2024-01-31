# $^ (all prerequisites): refers to whatever is after the ":"
# $@ (target): refers to whatever is before the ":"
# $< (first prerequisite): refers to the first thing that is after the ":"

CC = gcc
CFLAGS = -Wall -fPIC
LDFLAGS = -L. -ldummy

all: libdummy.so runner test

libdummy.so: libdummy.c
	$(CC) $(CFLAGS) $^ -shared -o $@ 

runner: runner.c libdummy.so
	LD_LIBRARY_PATH=. $(CC) $(CFLAGS) $< -o runner.out $(LDFLAGS)

test: test_runner.c libdummy.so
	$(CC) $(CFLAGS) $< -o test_runner.out $(LDFLAGS)
	LD_LIBRARY_PATH=. ./test_runner.out

clean:
	rm -f runner.out test_runner.out libdummy.so