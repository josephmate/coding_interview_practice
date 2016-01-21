

all: find_max

find_max.o: find_max.cpp find_max.hpp
	g++ -std=c++11 -c find_max.cpp

main.o: find_max.o find_max.hpp main.cpp 
	g++ -std=c++11 -c main.cpp 

find_max: find_max.o main.o find_max.hpp main.cpp 
	g++ -std=c++11 main.o find_max.o -o find_max

clean:
	rm -f *.o
	rm -f *.exe
	rm -f test
	rm -f find_max 
