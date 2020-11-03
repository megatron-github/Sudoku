/************************************************************************
    File: sudoku.cc
    Author: Truong Pham
    Date: 3/6/19
    Assignment:  Sudoku

    This program that take an input of a sudoku board and solve the
    board using the technique of backtracking. The process of solving
    and back tracking uses a first-in-last-out stack to save the data
    during each step of solving and back tracking. The program locate the
    most constrained location on the board and place smallest possible
    value on that position.

************************************************************************/

#include <iostream>
#include "sudokuboard.h"
#include "stack.h"

size_t constrained_place(sudokuboard board, size_t & row, size_t & col){
  // find the a place that can hold the least amount of possible values
  // on the board, and return the amount of the possible values

  size_t max_count = 10;

  // go to each cell on the sudoku board
  for(size_t r = 0; r < board.size(); r++){
    for(size_t c = 0; c < board.size(); c++){

      // check if the cell is blank (unsolved)
      if(board.blank_spot(r, c)){
        size_t count = 0;

        // count the numbers of possible solution for the cell
        for(size_t n = 1; n <= board.size(); n++){
          if(board.can_place(r, c, n)){
            count++;
          }
        }

        // record the location that have the least number of possible
        // solution as well as the numbers of solution
        if((count != 0) && (count < max_count)){
          max_count = count;
          row = r;
          col = c;
        }
      }
    }
  }

  // if there is no more possible solution for each empty cell
  // on the board (or max-count never change), return zero
  if(max_count == 10){
    return 0;
  }
  return max_count;
}

bool need_backtrack(sudokuboard & board, stack & stack){
  // retrun false to stop the back track if the previous move have another
  // solution. Otherwise, return true to keep back track

  // increase the previous solution to prevent the board from placing
  // the same smallest possible value
  size_t n = stack.top() + 1;
  stack.pop();

  // remove the previous solution to scan the board again
  size_t col = stack.top();
  stack.pop();
  size_t row = stack.top();
  stack.pop();
  board.remove(row, col);

  // return true to keep back tracking if there
  // is no other solution for the previous move.
  while(!board.can_place(row, col, n)){
    if(n > 9){
      return true;
    }
    n++;
  }

  // if another solution is found for the previous move, place the new
  // solution on the board (record the new move) and return false
  // to stop back tracking
  char num = n + '0';
  stack.push(row);
  stack.push(col);
  stack.push(n);
  board.place(row, col, num);
  return false;

}

void proceed(sudokuboard & board, stack & stack, size_t row, size_t col){
  // With each empty spot, place the smallest possible numeral into the spots,
  // and record the move by saving the location and the numeral in a stack

  size_t n = 1;

  // find the smallest possible numeral starting from one.
  while(!board.can_place(row, col, n)){
    n++;
  }

  // place the number to the empty spot and
  // save row, column, and the number
  char num = n + '0';
  stack.push(row);
  stack.push(col);
  stack.push(n);
  board.place(row, col, num);
}

void solve_puzzle(sudokuboard & board){
  // While the board has empty spot, find solution for each spot and save
  // each solution within a stack

  std::cout << "Solving... so wait for it..." << std::endl;
  size_t row = 0, col = 0, bt = 0;
  stack stack;

  // while the board still have empty spots, look for solution for each spots
  while(!board.solved()){

    // find the solution for each empty spot by looking for the spot with
    // the least possible amount of solution
    if(constrained_place(board, row, col) > 0){
      proceed(board, stack, row, col);
    }

    // if the board still has empty spots but no solution is found, back
    // track until a solution is found
    else{
      while(need_backtrack(board, stack)){
        bt++;

        // if there is no solution despite trials on every possible empty
        // spots, the board is unsovlable
        if(stack.empty()){
          return;
        }
      }
    }
  }
  std::cout << "Solved with " << bt << " back track steps" << std::endl;
}

int main(){
  // main program

  sudokuboard board;
  std::string row = "";
  std::cout << "Make a sudoku board..." << std::endl;

  // Copy the user-input data into the created board row by row.
  for(size_t r = 0; r < board.size(); r++){
    std::cin >> row;
    for(size_t c = 0; c < board.size(); c++){
      board.place(r, c, row[c]);
    }
  }

  // solve the board and print.
  solve_puzzle(board);
  board.print();
}
