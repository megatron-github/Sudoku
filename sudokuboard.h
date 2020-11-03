/************************************************************************
    File: sudokuboard.h

    Description: A sudokuboard class header. The header declares instances 
                 and methods that user can use with the sudokuboard class 
                 to build and solve the sudoku board.

************************************************************************/

#include <cstdlib>

class sudokuboard {
  // the class that create methods and properties for a sudoku board

  private:

  size_t _size = 9; // size to regulate the dimension
  char **board;     // create the board and tracking data on the board.

 public:

  sudokuboard();
  // constructor

  /*** const member functions ***/

  size_t size() const;
  // return the size of a sudoku board

  void print() const;
  // write the board to std::cout

  bool can_place(size_t r, size_t c, size_t n) const;
  // return true iff the board would allow placing n at (r,c).
  // false otherwise

  bool blank_spot(size_t r, size_t c) const;
  // return true if the spot is not filled by a number already.

  bool solved() const;
  // return true iff there are no blank spots on the board

  /*** non-const member functions ***/

  void place(size_t r, size_t c, char n);
  // place numeral n at position (r,c)

  void remove(size_t r, size_t c);
  // remove the numeral at position (r,c)

};
