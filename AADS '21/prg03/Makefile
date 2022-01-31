CC = g++
CFLAGS  = -Wall -Wextra -pedantic -std=c++17 

list: Node.o  SkipList.o SkipListAdd.o main.o
	$(CC) $(CFLAGS) -o $@ $^

main:   main.cpp Master.h
	$(CC) $(CFLAGS) -c $<

SkipList: SkipList.cpp SkipList.h Node.h Master.h
	$(CC) $(CFLAGS) -c $<

SkipListAdd: SkipListAdd.cpp SkipList.h Node.h Master.h
	$(CC) $(CFLAGS) -c $<

Node: Node.cpp Node.h Master.h
	$(CC) $(CFLAGS) -c $<

