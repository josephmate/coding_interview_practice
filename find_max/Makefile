

all: find_max

find_max.o: find_max.cpp find_max.hpp
	g++ -std=c++11 -c find_max.cpp

main.o: find_max.o find_max.hpp main.cpp 
	g++ -std=c++11 -c main.cpp 

test_find_max.o: test_find_max.cpp
	g++ -std=c++11 -c test_find_max.cpp 

find_max: find_max.o main.o find_max.hpp main.cpp test
	g++ -std=c++11 main.o find_max.o -o find_max

test: test_find_max.o find_max.o
	g++ -std=c++11 test_find_max.o find_max.o -lboost_unit_test_framework -o test
	./test


clean:
	rm -f *.o
	rm -f *.exe
	rm -f test
	rm -f find_max 
