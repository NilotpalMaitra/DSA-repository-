#include <iostream>

#define MAX_SIZE 100

// Stack class
class Stack {
private:
    int top;
    int stackArray[MAX_SIZE];

public:
    Stack() {
        top = -1;
    }

    // Push an element onto the stack
    void push(int value) {
        if (top == MAX_SIZE - 1) {
            std::cout << "Stack overflow! Cannot push element onto the stack." << std::endl;
            return;
        }
        stackArray[++top] = value;
    }

    // Pop an element from the stack
    void pop() {
        if (isEmpty()) {
            std::cout << "Stack underflow! Cannot pop element from the stack." << std::endl;
            return;
        }
        --top;
    }

    // Get the top element of the stack
    int peek() {
        if (isEmpty()) {
            std::cout << "Stack is empty! Cannot retrieve top element." << std::endl;
            return -1;
        }
        return stackArray[top];
    }

    // Check if the stack is empty
    bool isEmpty() {
        return top == -1;
    }

    // Print the stack
    void print() {
        if (isEmpty()) {
            std::cout << "Stack is empty!" << std::endl;
            return;
        }
        std::cout << "Stack: ";
        for (int i = top; i >= 0; --i) {
            std::cout << stackArray[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    Stack myStack;

    // Push elements onto the stack
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);
    myStack.push(40);

    // Print the stack
    myStack.print();

    // Pop an element from the stack
    myStack.pop();

    // Print the updated stack
    myStack.print();

    // Get the top element of the stack
    int topElement = myStack.peek();
    std::cout << "Top element of the stack: " << topElement << std::endl;

    return 0;
}
