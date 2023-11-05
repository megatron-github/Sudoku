/***************************************************************************************************
    File: stack.h

    Description: A stack class header.

        The header declares instances and methods in the stack class that user can use to save and
        record each move during the process of solving the sudoku board. Using the stack as a data
        structure, we can solve soduku with the the back tracking method.

***************************************************************************************************/

#include <cstdlib>

/* Define the data type double as stack_element */
typedef size_t stack_element;

/* The stack is based on the data structure of linked list*/
struct stack_node {
    stack_element data;     // node data
    stack_node *next;       // node pointer
    stack_node(const stack_element & data, stack_node *nxt);
};

/* the class that create methods and properties of a stack */
class stack {

    private:
        stack_node *_top;   // node pointer
        void _init();       // memory management helper method for constructor

    public:

        // a method that push (save) user's data into the linked list
        void push(const stack_element & item);

        // a method that pop (remove) user's data from the linked list
        void pop();

        // a method that tell the user the data that the pointer is pointing
        // at in the linked list
        stack_element top() const;

        // a method that tell the user if the linked list is empty or not
        bool empty() const;

};
