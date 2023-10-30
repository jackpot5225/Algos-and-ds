#include <iostream>

// code for a simple stack data structure

class Stack {

    private:

        int top; // holds the index of the top value of the stack
    
    public:

        int array[10]; // creates the array to hold the stack elements, as well as the max number of elements it can hold: 10

        Stack () { // initalizes a stack

            top = -1;

        }
        
        void push (int value) { // function to push a value onto the stack

            if (top >= 9) { // checks if the stack is full

                std::cout << "stack overflow \n";

            } else { // pushes the value onto the stack

                array[++top] = value;

            }

        }

        void pop () { // function to pop a value off of the stack

            if (top < 0) { // checks if the stack is empty

                std::cout << "stack underflow \n";

            } else { // pops the top value off the stack

                --top;

            }

        }

        int peek () { // peeks the top value of the stack
            
            if (top < 0) { // checks if the stack is empty

                std::cout << "stack is empty \n";
                return 0;

            } else { // returns the top value of the stack

                int theTop = array[top];
                return theTop;

            }

        }

};

int main () {

    Stack aStack = Stack();
    return 0;

}