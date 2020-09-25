all: cliente

cliente: cliente.o complexos.o
	gcc cliente.o complexos.o -lm -o cliente

cliente.o: cliente.c complexos.h
	gcc -std=c99 -Wall -Werror -c cliente.c

complexos.o: complexos.c complexos.h
	gcc -std=c99 -Wall -Werror -c -complexos.c 