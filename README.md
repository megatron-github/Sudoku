# Sudoku

## Background

Sudoku is a puzzle where you fill in numbers `1-9` on a `9x9` board such that no number is duplicated in any row, column, or `3x3` sub-grid. The program allows the user to check whether a Sudoku puzzle is solvable or not. Given an input to the program consisting of `9` lines of `9` characters, each character is a numeral `1–9` or an underscore `_` to represent a blank square. The output must similarly consist of `9` lines of `9` characters each. Each character must be a numeral `1–9`, and the whole output must be a solution to the input puzzle.

## Approach

There are many different algorithms that can be used to solve Sudoku puzzles, including constraint programming and rule-based methods. However, the backtracking algorithm is one of the most commonly used algorithms for solving Sudoku puzzles.

We use the backtracking algorithm to find and place the smallest acceptable numbers in empty squares until there are no more empty squares left. If a number is placed in a square that violates the rules of Sudoku, the algorithm backtracks and tries a different number. That is, during the backtracking process, we return to the most recent solved square and replace the solution with the next acceptable number. We continues this process until the puzzle is solved. With each solving step, we choose the most constrained square on the board — the one that will accept the fewest numerals.

In our implementation, we facilitate the backtracking algorithm using a linked-list-based stack. The First-In-First-Out behavior of the stack allows us to streamline the process of saving and recalling the most recent solving steps. The nature of a linked-list would make it easier for us to modify and update the stack.

## Sample Run

Here is an example of an execution of the program. The program asks user to input a 9x9 Sudoku with pre-filled entries. Then the program will calculate and output the total number of backtracked steps and a solved board.
```
Input a sudoku board...
85___24__
72______9
__4______
___1_7__2
3_5___9__
_4_______
____8__7_
_17______
____36_4_
Solving...
Solved with 85635 back track steps
859612437
723854169
164379528
986147352
375268914
241593786
432981675
617425893
598736241
```
## How to run
The program is compiled using the G++ Compiler. To compile the program, use the given Makefile and within the same directory, execute:
```
mkdir builds
make
```

To run the program:
```
ls builds/sudoku
builds/sudoku
builds/sudoku < test/sample.in
```

## Author
Truong Pham

