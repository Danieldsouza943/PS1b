CC = g++
CFLAGS = --std=c++17 -Wall -Werror -pedantic -g
LIB = -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system -lboost_unit_test_framework
# Your .hpp files
DEPS = FibLFSR.hpp PhotoMagic.hpp
# Your compiled .o files
OBJECTS = FibLFSR.o PhotoMagic.o main.o test.o
# The name of your programs
PROGRAM1 = PhotoMagic
PROGRAM2 = test

.PHONY: all clean lint

all: $(PROGRAM1) PhotoMagic.a $(PROGRAM2)

$(PROGRAM1): main.o PhotoMagic.o FibLFSR.o
	$(CC) $(CFLAGS) -o $@ $^ $(LIB)

PhotoMagic.a: PhotoMagic.o FibLFSR.o
	ar rvs $@ $^

$(PROGRAM2): test.o FibLFSR.o PhotoMagic.o
	$(CC) $(CFLAGS) -o $@ $^ $(LIB)

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm -f *.o $(PROGRAM1) PhotoMagic.a $(PROGRAM2)

lint:
	cpplint *.cpp *.hpp
