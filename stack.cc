/************************************************************************
    File: stack.cc

    Description:  A stack class that created by a linked list and node 
                  pointers. Each node in the that made up the stack allow 
                  user to input data and recall, or remove the input data. 
                  Stack uses methods such as push, pop, top, and empty to 
                  have the first-in-last-out methods in which similar to 
                  the real world stacking.

************************************************************************/
#include <iostream>
#include "stack.h"

void stack::_init(){
  // memory management helper method for constructor

  _top = nullptr;
}

stack_node::stack_node(const stack_element & dta, stack_node *nxt){
  // a class that allow user to take data and next as parameter (or
  // allow user to give stack_node an arguement)

  data = dta;
  next = nxt;
}

void stack::push(const stack_element & item){
  // a method that push (save) user's data into the linked list

  _top = new stack_node(item, _top);
}

void stack::pop(){
  // a method that pop (remove) user's data from the linked list

  stack_node *corpse = _top;
  _top = _top->next;
  delete corpse;
}

stack_element stack::top()const{
  // a method that tell the user the data that the pointer is pointing
  // at in the linked list

  return _top->data;
}

bool stack::empty()const{
  // a method that tell the user if the linked list is empty or not

  return _top == nullptr;
}
