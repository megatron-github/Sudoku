/************************************************************************
    File: sudokuboard.cc
    Author: Truong Pham
    Date: 3/6/19
    Assignment:  Sudoku

    A sudokuboard class that create a sudoku board using a dynamic array
    or array. The class has methods that can return the size of the board,
    print the board, check if the board allows to place certain item, check
    if a place on the board is empty, and if the whole board is solved.
    Other methods in the class also allows the user to place items on or
    remove items off the board.

************************************************************************/

#include <iostream>
#include "sudokuboard.h"

/*** Constructor ***/

sudokuboard::sudokuboard(){
  // Creating a sudoku board.

  // create a double nested list
  board = new char*[_size];
  for(size_t r = 0; r < _size; r++){
    board[r] = new char[_size];
  }
}

/*** const member functions ***/

size_t sudokuboard::size() const{
  // return the size of a sudoku board.

  return _size;
}

void sudokuboard::print() const {
  // write the board to std::cout

  // go to each cell of the board and print the data
  for(size_t r = 0; r < _size; r++){
    for(size_t c = 0; c < _size; c++){
      std::cout << board[r][c];
    }

    // create new row every time a column is full
    std::cout << "\n";
  }
}

bool sudokuboard::can_place(size_t r, size_t c, size_t n) const{
  // return true iff the board would allow placing value n at (r,c).
  // false otherwise

  // return false if value n is not in the range 1-9 (size_t is unsigned)
  if(n > 9){
    return false;
  }

  char new_num = n + '0';

  // check if the value n is already existed in
  // an entire row or entire column
  for(size_t i = 0; i < _size; i++){
    if((board[r][i] == new_num) || (board[i][c] == new_num)){
      return false;
    }
  }

  // row and column represent first corner of
  // each small 3x3 squares in the 9x9 board
  r = (r / 3) * 3;
  c = (c /3 ) * 3;

  // check if value n is already in each cell
  // of the small relative 3x3 or not
  for(size_t i = 0; i < 3; i++){
    for(size_t j = 0; j < 3; j++){
      if(board[r + i][c + j] == new_num){
        return false;
      }
    }
  }
  return true;
}

bool sudokuboard::blank_spot(size_t r, size_t c) const{
  // return true if the spot is not already solved by a number,
  // false otherwise

  return board[r][c] == '_';
}

bool sudokuboard::solved() const{
  // return true iff there are no blank spots on the board.

  // if there is a unsolved spot in the entire board, the board is not solved
  for(size_t r = 0; r < _size; r++){
    for(size_t c = 0; c < _size; c++){
      if(board[r][c] == '_'){
        return false;
      }
    }
  }
  return true;
}

/*** non-const member functions ***/

void sudokuboard::place(size_t r, size_t c, char n){
  // place numeral n at position (r, c)

  board[r][c] = n;
}

void sudokuboard::remove(size_t r, size_t c){
  // remove the numeral at position (r, c)

  board[r][c] = '_';
}
