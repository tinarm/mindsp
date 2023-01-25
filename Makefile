src = $(wildcard mindsp/*.c)
obj = $(src:.c=.o)

test_src = $(wildcard test/*.c)
test_obj = $(test_src:.c=.o)

CC = gcc

CFLAGS = -std=c99 -I./mindsp
LDFLAGS = -lm

.PHONY: all
all: clean libmindsp mindsptest

libmindsp: $(obj)
	ar -rcs $@.ar $^

mindsptest: $(test_obj) libmindsp.ar
	$(CC) -Wall -Wextra -Wpedantic -o $@ $^ $(CFLAGS) $(LDFLAGS)

.PHONY: clean
clean:
	rm -f $(obj) $(test_obj) libmindsp.ar mindsptest
