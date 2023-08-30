
#include <iostream>
#define MAX_SIZE 100
Using namespace std;
class Stack {
private:
    int top;
    int stackArray[MAX_SIZE];

public:
    Stack() {
        top = -1;
    }

    void push(int value) {
        if (top == MAX_SIZE - 1) {
            cout << "Stack overflow! Cannot push element " << value <<endl;
            return;
        }
        stackArray[++top] = value;
        cout << "Pushed element " << value << " into the stack." <<endl;
    }

    void pop() {
        if (top == -1) {
           cout << "Stack underflow! Cannot pop element from an empty stack." <<endl;
            return;
        }
        int poppedValue = stackArray[top--];
        cout << "Popped element: " << poppedValue <<endl;
    }

    int peek() {
        if (top == -1) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return stackArray[top];
    }

    bool isEmpty() {
        return (top == -1);
    }
};

int main() {
    Stack myStack;

    myStack.push(5);
    myStack.push(10);
    myStack.push(15);

    cout << "Top element of the stack: " << myStack.peek() <<endl;

    myStack.pop();
    myStack.pop();

    cout << "Is the stack empty? " << (myStack.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}


