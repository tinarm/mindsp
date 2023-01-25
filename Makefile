src = $(wildcard mindsp/*.c)
obj = $(src:.c=.o)

test_src = $(wildcard test/*.c)
test_obj = $(test_src:.c=.o)

CC = gcc

CFLAGS = -std=c99 -I./mindsp
LDFLAGS = -lm

OUT_DIR = out

.PHONY: all
all: clean libmindsp mindsptest

libmindsp: $(obj)
	ar -rcs $@.ar $^
	mkdir -p $(OUT_DIR)
	mv $@.ar $(OUT_DIR)

mindsptest: $(test_obj) $(OUT_DIR)/libmindsp.ar
	$(CC) -Wall -Wextra -Wpedantic -o $@ $^ $(CFLAGS) $(LDFLAGS)
	mkdir -p $(OUT_DIR)
	mv $@ $(OUT_DIR)

.PHONY: clean
clean:
	rm -f $(obj) $(test_obj) $(OUT_DIR)/libmindsp.ar $(OUT_DIR)/mindsptest
