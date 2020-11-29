CFLAGS = -std=c99 -Wall -Werror -Werror=vla -g
LDFLAGS = -lm

.PHONY: all clean

all: diadeuber max_heap

diadeuber: *.c
	gcc $(CFLAGS) *.c -o diadeuber $(LDFLAGS)

max_heap: *.c
	gcc $(CFLAGS) *.c -o max_heap $(LDFLAGS)

clean:
	rm -f diadeuber
	rm -f *.o
