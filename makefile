PROGRAM_NAME = disk-tree.cpp
CC = g++#gcc
CFLAGS = -g -Wall -O2 #-std=c99 

all: $(PROGRAM_NAME)
	$(CC) $(CFLAGS) -o main.out $(PROGRAM_NAME)

clean:
	rm -f main.out
	rm -rf main.out.dSYM
