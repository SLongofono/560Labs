mst: main.o tree.o
	g++ -g -std=c++11 tree.o main.o -o mst

main.o: Main.cpp Tree.h
	g++ -g -std=c++11 -c Main.cpp

tree.o: Tree.h Tree.hpp
	g++ -g -std=c++11 -c Tree.hpp

clean:
	rm mst main.o
