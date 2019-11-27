CC := g++
CFLAGS := -Wall -Wextra -O3 -g -std=c++14
SRC := $(wildcard src/*.cpp) $(wildcard include/*.hpp)
INC := -Iinclude/
EXE := bin/test

all:
	$(CC) -o $(EXE) $(CFLAGS) $(INC) $(SRC)
