PROGRAM_NAME = consecutive_prime_sum.c
CC = gcc
CFLAGS = -std=c99 -g -Wall -O2

all: $(PROGRAM_NAME)
	$(CC) $(CFLAGS) -o main.out $(PROGRAM_NAME)

clean:
	rm -f main.out
	rm -rf main.out.dSYM
