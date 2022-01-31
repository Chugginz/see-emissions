CC = g++
CFLAGS  = -Wall -Wextra -pedantic -std=c++17 

ttTree: Node.o  NodeInsert.o  Two3T.o  main.o
	$(CC) $(CFLAGS) -o $@ $^

main.o:   main.cpp master.h
	$(CC) $(CFLAGS) -c $<

Two3T.o: Two3T.cpp Two3T.h Node.h master.h
	$(CC) $(CFLAGS) -c $<


NodeInsert.o: NodeInsert.cpp Node.h master.h
	$(CC) $(CFLAGS) -c $<

Node.o: Node.cpp Node.h master.h
	$(CC) $(CFLAGS) -c $<

