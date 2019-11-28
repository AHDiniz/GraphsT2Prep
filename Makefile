CC := g++
CFLAGS := -Wall -Wextra -O3 -g -std=c++14 -lm
SRC := $(wildcard src/*.cpp)
INC := -Iinclude/
EXE := bin/test

all:
	$(CC) -o $(EXE) $(CFLAGS) $(INC) $(SRC)
