bq: main.o bq.o
	g++ -g -std=c++11 bq.o main.o -o bq

main.o: main.cpp BQueue.h
	g++ -g -std=c++11 -c main.cpp

bq.o: BQueue.h BQueue.hpp
	g++ -g -std=c++11 -c BQueue.hpp

clean:
	rm bq main.o
