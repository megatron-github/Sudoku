all: sudoku

sudoku: sudoku.o sudokuboard.o stack.o
	g++ -o builds/sudoku builds/*

stack.o: stack/*
	g++ -c stack/stack.cc -o builds/stack.o

sudoku.o: sudoku/* stack/stack.h
	g++ -c sudoku/sudoku.cc -o builds/sudoku.o

sudokuboard.o: sudoku/*
	g++ -c sudoku/sudokuboard.cc -o builds/sudokuboard.o

clean:
	rm -rf *~ builds/*
