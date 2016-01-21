

all: test

linked_list.o: linked_list.cpp linked_list.hpp
	g++ -std=c++11 -c linked_list.cpp

test_linked_list.o: test_linked_list.cpp
	g++ -std=c++11 -c test_linked_list.cpp 

test: test_linked_list.o linked_list.o
	g++ -std=c++11 test_linked_list.o linked_list.o -lboost_unit_test_framework -o test
	./test


clean:
	rm -f *.o
	rm -f *.exe
	rm -f test
