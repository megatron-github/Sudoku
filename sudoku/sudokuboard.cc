/***************************************************************************************************
    File: sudokuboard.cc

    Description:

        A sudokuboard class that create a sudoku board using a dynamic nested array.
        The class has methods that can return the size of the board, displays the
        board, and check if a location on the board is empty, allowed to place certain
        number, or the board is solved. The class also allows user to place and remove items
        on and off the board.

***************************************************************************************************/
#include <iostream>
#include "sudokuboard.h"

/*** Constructor ***/
sudokuboard::sudokuboard() {
    /* Create a sudoky board instance */

    // create a double nested list
    board = new char*[_size];
    for (size_t r = 0; r < _size; r++) {
        board[r] = new char[_size];
    }
}

size_t sudokuboard::size() const{
    /* Return the size of a sudoku board */

    return _size;
}

void sudokuboard::print() const {
    /* Displays the board using std::cout */

    for (size_t r = 0; r < _size; r++) {
        for (size_t c = 0; c < _size; c++) {
            std::cout << board[r][c];
        }
        std::cout << "\n";
    }
}

bool sudokuboard::can_place(size_t r, size_t c, size_t n) const {
    /* Return true iff it is legal to place the number n
    onto the board at (r,c). Ffalse otherwise */

    // return false if value n is not in the range 1-9 (size_t is unsigned)
    if (n > 9) { return false; }

    char new_num = n + '0';

    // check if the value n is found existed in a given row or column
    for (size_t i = 0; i < _size; i++) {
        if ((board[r][i] == new_num) || (board[i][c] == new_num)) {
            return false;
        }
    }

    // row and column represent first corner of
    // each small 3x3 squares in the 9x9 board
    r = (r / 3) * 3;
    c = (c / 3) * 3;

    // check if value n is already in each cell of the small relative 3x3 or not
    for (size_t i = 0; i < 3; i++) {
        for (size_t j = 0; j < 3; j++) {
            if (board[r + i][c + j] == new_num) {
                return false;
            }
        }
    }
    return true;
}

bool sudokuboard::blank_spot(size_t r, size_t c) const {
    /* Return true if the given location on the board empty */

    return board[r][c] == '_';
}

bool sudokuboard::solved() const{
    /* Return true iff the entire board is filled out */

    // if there is a unsolved spot in the entire board, the board is not solved
    for (size_t r = 0; r < _size; r++) {
        for (size_t c = 0; c < _size; c++) {
            if (board[r][c] == '_') {
                return false;
            }
        }
    }
    return true;
}

void sudokuboard::place(size_t r, size_t c, char n){
    /* Place the given number n onto the board at (r, c) */

    board[r][c] = n;
}

void sudokuboard::remove(size_t r, size_t c){
    /* Remove the item from the board at (r, c) */

    board[r][c] = '_';
}
