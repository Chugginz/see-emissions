CC = g++
CFLAGS  = -Wall -Wextra -pedantic -std=c++17 

list: Node.o  OLinkedList.o OLinkedListAdd.o main.o
	$(CC) $(CFLAGS) -o $@ $^

main:   main.cpp Master.h
	$(CC) $(CFLAGS) -c $<

OLinkedList: OLinkedList.cpp OLinkedList.h Node.h Master.h
	$(CC) $(CFLAGS) -c $<

OLinkedListAdd: OLinkedListAdd.cpp OLinkedList.h Node.h Master.h
	$(CC) $(CFLAGS) -c $<

Node.o: Node.cpp Node.h Master.h
	$(CC) $(CFLAGS) -c $<

