/************************************************************************
    File: stack.h

    Description: A stack class header. The header declares instances and 
    		 methods in the stack class in which the user can use to 
		 save and record each move during the process of the 
		 sudoku board. The methods of the stack class make it 
		 possible for user to implement the back tracking 
		 methods.

************************************************************************/

#include <cstdlib>

typedef size_t stack_element;
// name the data type double as stack_element

struct stack_node{
	// the data structure of a node, in which node
	// takes data and pointer as arguements

	stack_element data; // node data
	stack_node *next;   // node pointer
	stack_node(const stack_element & data, stack_node *nxt);
};

class stack {
	// the class that create methods and properties of a stack

private:

  stack_node *_top; // node pointer
  void _init();  // memory management helper method for constructor

public:

  void push(const stack_element & item);
	// a method that push (save) user's data into the linked list

  void pop();
	// a method that pop (remove) user's data from the linked list

  stack_element top() const;
	// a method that tell the user the data that the pointer is pointing
  // at in the linked list

  bool empty() const;
	// a method that tell the user if the linked list is empty or not

};
