/***************************************************************************************************
    File: stack.cc

    Description:

        A linked-list-based stack class that allows user to save data, remove, and check
        the input data using methods such as push, pop, top, and empty. The class displays the
        conceptsfirst-in-last-out.

***************************************************************************************************/
#include <iostream>
#include "stack.h"

void stack::_init() {
    /* memory management helper method for constructor */

    _top = nullptr;
}

stack_node::stack_node(const stack_element & value, stack_node *nxt) {
    /* A class to create a node in the linked-list-based stack */

    data = value;
    next = nxt;
}

void stack::push(const stack_element & item) {
    /* A method that push (save) user's data onto the stack */

    _top = new stack_node(item, _top);
}

void stack::pop() {
    /* A method that pop (remove) user's data from the stack */

    stack_node *top_node = _top;
    _top = _top->next;
    delete top_node;
}

stack_element stack::top() const {
    /* A method to return user's the data on the top of the stack */

    return _top->data;
}

bool stack::empty() const {
    /* A method to check if the stack is empty or not */

    return _top == nullptr;
}
