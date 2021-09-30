#Makefile for memLeak

CC = gcc
CCFLAGS = -std=c99 -Iinclude
all: memLeak

memLeak: memLeak.o utils.o
	$(CC) $(CCFLAGS) obj/memLeak.o obj/utils.o -o memLeak

memLeak.o: src/memLeak.c
	@mkdir -p obj
	$(CC) $(CCFLAGS) -c src/memLeak.c -o obj/$@

utils.o: src/utils.c include/utils.h
	@mkdir -p obj
	$(CC) $(CCFLAGS) -c src/utils.c -o obj/$@

clean:
	rm -rf obj/*o memLeak
