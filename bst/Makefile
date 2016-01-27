
C_HEADERS=$(wildcard *.h)
CPP_HEADERS=$(wildcard *.hpp)

C_SOURCES=$(wildcard *.c)
CPP_SOURCES=$(wildcard *.cpp)

C_OBJECTS=$(patsubst %.c, %.o, $(C_SOURCES))
C_OBJECTS_NO_MAINS := $(filter-out main.%,$(C_OBJECTS))
C_OBJECTS_NO_MAINS := $(filter-out test_%,$(C_OBJECTS_NO_MAINS))
CPP_OBJECTS=$(patsubst %.cpp, %.o, $(CPP_SOURCES))
CPP_OBJECTS_NO_MAINS := $(filter-out main.%,$(CPP_OBJECTS))
CPP_OBJECTS_NO_MAINS := $(filter-out test_%,$(CPP_OBJECTS_NO_MAINS))

# TODO: This will need to be updated to allow having multiple main files.
# we cannot just include all the object files because multiple might have a
# main function.

CFLAGS=-std=c++11
CPP_COMPILER=g++
C_COMPILER=gcc

all: test main

$(C_OBJECTS): $(C_HEADERS) $(C_SOURCES)
	$(C_COMPILER) -c $(C_SOURCES)

$(CPP_OBJECTS): $(CPP_HEADERS) $(CPP_SOURCES)
	$(CPP_COMPILER) $(CFLAGS) -c $(CPP_SOURCES)

main: $(CPP_OBJECTS) $(C_OBJECTS)
	$(CPP_COMPILER) $(CFLAGS) main.o $(CPP_OBJECTS_NO_MAINS) $(C_OBJECTS_NO_MAINS) -o main

test: $(CPP_OBJECTS) $(C_OBJECTS)
	$(CPP_COMPILER) $(CFLAGS) test_*.o $(CPP_OBJECTS_NO_MAINS) $(C_OBJECTS_NO_MAINS) -lboost_unit_test_framework -o test
	./test


clean:
	rm -f *.o
	rm -f *.exe
	rm -f test
	rm -f *.stackdump
