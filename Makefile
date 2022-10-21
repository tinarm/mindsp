src = $(wildcard dsp/*.c)
obj = $(src:.c=.o)

LDFLAGS = #-lz -lm

dsp: $(obj)
	$(CC) -Wall -o $@ $^ $(LDFLAGS)

.PHONY: clean
clean:
	rm -f $(obj) dsp

