
#include <iostream>
Using namespace std;
// Node structure for stack
struct Node {
    int data;
    Node* next;
};

// Class for stack
class Stack {
private:
    Node* top;

public:
    Stack() {
        top = NULL;
    }

    // Push an element onto the stack
    void push(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = top;
        top = newNode;
    }

    // Pop an element from the stack
    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty. Cannot pop." << endl;
        } else {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }

    // Check if the stack is empty
    bool isEmpty() {
        return top == NULL;
    }

    // Display the top element of the stack
    void displayTop() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
        } else {
            cout << "Top element: " << top->data << endl;
        }
    }
};

int main() {
    Stack stack;

    stack.push(5);
    stack.push(10);
    stack.push(15);
    stack.displayTop();  // Output: Top element: 15

    stack.pop();
    stack.displayTop();  // Output: Top element: 10

    stack.pop();
    stack.displayTop();  // Output: Top element: 5

    stack.pop();
    stack.displayTop();  // Output: Stack is empty. 

    return 0;
}

