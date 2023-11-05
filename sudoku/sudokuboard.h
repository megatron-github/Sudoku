/***************************************************************************************************
    File: sudokuboard.h

    Description:

        A sudokuboard class header to declare the instances and methods users with to
        build and solve the sudoku board.

***************************************************************************************************/
#include <cstdlib>

class sudokuboard {
    /* The class that create methods and properties for a sudoku board */

    private:
        size_t _size = 9;   // size to regulate the dimension
        char **board;       // create the board and tracking data on the board.

    public:

        /* Constructor */
        sudokuboard();

        /* Return the size of a sudoku board */
        size_t size() const;

        /* Displays the board using std::cout */
        void print() const;

        /* Return true iff it is legal to place the number n
        onto the board at (r,c). Ffalse otherwise */
        bool can_place(size_t r, size_t c, size_t n) const;

        /* Return true if the given location on the board empty */
        bool blank_spot(size_t r, size_t c) const;

        /* Return true iff the entire board is filled out */
        bool solved() const;

        /* Place the given number n onto the board at (r, c) */
        void place(size_t r, size_t c, char n);

        /* Remove the item from the board at (r, c) */
        void remove(size_t r, size_t c);

};
