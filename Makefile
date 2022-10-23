src = $(wildcard dsp/*.c)
obj = $(src:.c=.o)

test_src = $(wildcard test/*.c)
test_obj = $(test_src:.c=.o)

LDFLAGS = #-lz -lm

.PHONY: all
all: clean libdsp libdsptest

libdsp: $(obj)
	$(CC) -Wall -Wextra -o $@ $^ $(LDFLAGS)

libdsptest: $(test_obj)
	$(CC) -Wall -Wextra -o $@ $^ $(LDFLAGS)

.PHONY: clean
clean:
	rm -f $(obj) libdsp libdsptest

