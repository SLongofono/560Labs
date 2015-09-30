lab9: main.o
	g++ -g -std=c++11 main.o PreconditionViolationException.o -o lab9

main.o: main.cpp BinarySearchTree.h Queue.h Node.h PreconditionViolationException.h
	g++ -g -std=c++11 -c main.cpp

PreconditionViolationException.o: PreconditionViolationException.h PreconditionViolationException.cpp
	g++ -g -std=c++11 -c PreconditionViolationException.cpp

clean:
	rm lab9 main.o PreconditionViolationException.o
