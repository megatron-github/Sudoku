/***************************************************************************************************
    File: sudoku.cc

    Description:

    This program that take an input of a sudoku board and solve the board using the
    backtracking method. A linked-list-based stack is implemented to facilitate process
    of saving and backtracking data. The program starts to solve the board by finding
    the most constrained location on the board and place smallest possible value onto
    that position.

***************************************************************************************************/
#include <iostream>
#include "sudokuboard.h"
#include "../stack/stack.h"

bool need_backtrack(sudokuboard & board, stack & stack) {
    /* Retrun false to stop backtracking when a solution for the previous move is found.
    Otherwise, return true to keep backtrack */

    // increase the previous solution
    size_t number = stack.top() + 1;
    stack.pop();

    // remove the previous solution to scan the board again
    size_t col = stack.top();
    stack.pop();
    size_t row = stack.top();
    stack.pop();
    board.remove(row, col);

    // return true to keep back tracking if no solution is found for the previous move.
    while (!board.can_place(row, col, number)) {
        if (number > 9) {
            return true;
        }
        number++;
    }

    // if another solution is found for the previous move, save it and
    // replace the previous solution
    char solution = number + '0';
    stack.push(row);
    stack.push(col);
    stack.push(number);
    board.place(row, col, solution);
    return false;
}

void solve(sudokuboard & board, stack & stack, size_t row, size_t col) {
    /* Given a solvable empty spot, place the smallest possible number onto the spot,
    and record the move by saving the location and the numeral in a given stack */

    size_t number = 1;
    while (!board.can_place(row, col, number)) {
        number++;
    }

    // Place the number to the empty spot and save row, column, and the number
    char solution = number + '0';
    stack.push(row);
    stack.push(col);
    stack.push(number);
    board.place(row, col, solution);
}

size_t find_solvable_spot(sudokuboard board, size_t & row, size_t & col) {
    /* Find a place on the board that has the least amount of placeable values.
    Return the amount of the possible values */

    size_t max_count = 10;

    // go to each cell on the sudoku board
    for (size_t r = 0; r < board.size(); r++) {
        for (size_t c = 0; c < board.size(); c++) {
            // check if the cell is unsolved
            if(board.blank_spot(r, c)) {
                size_t count = 0;

                // count the numbers of possible solution for the cell
                for (size_t n = 1; n <= board.size(); n++) {
                    if (board.can_place(r, c, n)) {
                        count++;
                    }
                }

                // save the location that have the least number of possible solution
                if ((count != 0) && (count < max_count)) {
                    max_count = count;
                    row = r;
                    col = c;
                }
            }
        }
    }

    // if there is no more possible solution for each empty cell
    // on the board (or max-count never change), return zero
    if (max_count == 10){
        return 0;
    }
    return max_count;
}

void solve_puzzle(sudokuboard & board){
    /* While the board has empty spot, find solution for each spot and save it in a stack */

    std::cout << "Solving..." << std::endl;
    size_t row = 0, col = 0, bt_steps = 0;
    stack stack;

    // while the board still have empty spots, look for solution for each spots
    while(!board.solved()){

        // find the spot with the least possible amount of solution
        if (find_solvable_spot(board, row, col)) {
            solve(board, stack, row, col);
        }

        // if the board still has empty spots but no solution is found, backtrack
        else {
            while (need_backtrack(board, stack)) {
                bt_steps++;

                // if there a spot has no solution despite backtracking and trying
                // every possible solution, the board is unsovlable
                if (stack.empty()) {
                    return;
                }
            }
        }
    }
    std::cout << "Solved with " << bt_steps << " back track steps" << std::endl;
}

int main() {
  /* Main program */

  sudokuboard board;
  std::string row = "";
  std::cout << "Input a sudoku board..." << std::endl;

    // Copy the user-input data into the created board row by row.
    for(size_t r = 0; r < board.size(); r++) {
        std::cin >> row;
        for(size_t c = 0; c < board.size(); c++) {
            board.place(r, c, row[c]);
        }
    }

    // solve the board and display the result.
    solve_puzzle(board);
    board.print();
}
