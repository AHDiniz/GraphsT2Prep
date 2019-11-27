CC := g++
CFLAGS := -Wall -Wextra -Wpedantic -O3 -g
SRC := $(wildcard src/*.cpp)
INC := -Iinclude/
EXE := bin/prim

all:
	$(CC) -o $(EXE) $(CFLAGS) $(INC) $(SRC)
