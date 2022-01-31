CC = g++
CFLAGS  = -Wall -Wextra -pedantic -std=c++17 

bst: Node.o  BST.o BSTswap.o main.o
	$(CC) $(CFLAGS) -o $@ $^

main.o:   main.cpp Master.h
	$(CC) $(CFLAGS) -c $<

BST.o: BST.cpp BST.h Node.h Master.h
	$(CC) $(CFLAGS) -c $<

BSTswap.o: BSTswap.cpp BST.h Node.h Master.h
	$(CC) $(CFLAGS) -c $<

Node.o: Node.cpp Node.h Master.h
	$(CC) $(CFLAGS) -c $<

