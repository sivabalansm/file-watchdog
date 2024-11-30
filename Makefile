FLAGS = -Wall
OBJ = ./obj
SRC = ./src
BIN = ./bin
TEST = ./test
CC := gcc $(FLAGS)


.PHONY: all clean test

all: $(OBJ)/main.o
	[ -e "$(BIN)" ] || mkdir $(BIN)
	$(CC) $(OBJ)/main.o -o $(BIN)/filewatchd
	
$(OBJ)/main.o: $(SRC)/main.c
	[ -e "$(OBJ)" ] || mkdir $(OBJ)
	$(CC) -c $(SRC)/main.c -o $(OBJ)/main.o

test: all 
	$(TEST)/test.sh

clean: 
	rm $(OBJ)/*
	rm $(BIN)/*
