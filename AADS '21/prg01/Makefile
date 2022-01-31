CC = g++
CFLAGS  = -Wall -Wextra -pedantic -std=c++17 

list: Node.o  LinkedList.o main.o
	$(CC) $(CFLAGS) -o $@ $^

main.o:   main.cpp Master.h
	$(CC) $(CFLAGS) -c $<

LinkedList.o: LinkedList.cpp LinkedList.h Node.h Master.h
	$(CC) $(CFLAGS) -c $<

Node.o: Node.cpp Node.h Master.h
	$(CC) $(CFLAGS) -c $<

