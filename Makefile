debugFlag=-g
cc=/usr/bin/g++

p2: Card.o 3Card.o 
	$(cc) -o p2 3Card.o Card.o $(debugFlag)

3Card.o: 3Card.cpp  Card.h
	$(cc) -c 3Card.cpp $(debugFlag)

Card.o: Card.cpp Card.h 
	$(cc) -c Card.cpp $(debugFlag)


clean: 
	\rm -f *.o p2

