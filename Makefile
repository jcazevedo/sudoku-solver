CPP_FILES = $(wildcard src/*.cpp)
OBJ_FILES = $(patsubst src/%.cpp, obj/%.o, $(CPP_FILES))
CC_FLAGS = -Wall -Iinclude/
CC = g++
BIN = sudoku-solver

all: $(BIN)

$(BIN): $(OBJ_FILES)
	$(CC) -o $@ $(OBJ_FILES)

obj/%.o: src/%.cpp
	$(CC) $(CC_FLAGS) -c -o $@ $<

clean:
	rm -rf obj/* $(BIN)