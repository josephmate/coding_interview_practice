
HEADERS=$(wildcard *.hpp)
SOURCES=$(wildcard *.cpp)
OBJECTS=$(patsubst %.cpp, %.o, $(SOURCES))

# TODO: This will need to be updated to allow having multiple main files.
# we cannot just include all the object files because multiple might have a
# main function.

CFLAGS=-std=c++11
COMPILER=g++

all: test

$(OBJECTS): $(HEADERS) $(SOURCES)
	$(COMPILER) $(CFLAGS) -c $(SOURCES)

test: $(OBJECTS)
	$(COMPILER) $(CFLAGS) $(OBJECTS) -lboost_unit_test_framework -o test
	./test


clean:
	rm -f *.o
	rm -f *.exe
	rm -f test
	rm -f *.stackdump
