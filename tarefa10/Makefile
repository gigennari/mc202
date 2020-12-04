CFLAGS = -std=c99 -Wall -Werror -Werror=vla -g
LDFLAGS = -lm

.PHONY: all clean

all: corretor hashing

corretor: *.c
	gcc $(CFLAGS) *.c -o corretor $(LDFLAGS)

hashing: *.c
	gcc $(CFLAGS) *.c -o hashing $(LDFLAGS)

clean:
	rm -f corretor
	rm -f *.o