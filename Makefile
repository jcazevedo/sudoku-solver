OBJ_DIR = obj
CPP_FILES = $(wildcard src/*.cpp)
OBJ_FILES = $(patsubst src/%.cpp, $(OBJ_DIR)/%.o, $(CPP_FILES))
CC_FLAGS = -Wall -Iinclude/
CC = g++
BIN = sudoku-solver

$(shell [ -d "$(OBJ_DIR)" ] || mkdir -p $(OBJ_DIR))

all: $(BIN)

$(BIN): $(OBJ_FILES)
	$(CC) -o $@ $(OBJ_FILES)

obj/%.o: src/%.cpp
	$(CC) $(CC_FLAGS) -c -o $@ $<

clean:
	rm -rf obj/* $(BIN)