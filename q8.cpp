
#include <iostream>
#include <queue>
Using namespace std; 
class Stack {
private:
    queue<int> q1, q2;

public:
    // Push operation
    void push(int data) {
        // Enqueue the new element into q1
        q1.push(data);
    }

    // Pop operation
    int pop() {
        if (q1.empty()) {
            cout << "Stack is empty." << endl;
            return -1; // Assuming -1 represents an empty stack
        }

        // Transfer (n-1) elements from q1 to q2
        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }

        // Dequeue and return the last element in q1 (top of the stack)
        int poppedElement = q1.front();
        q1.pop();

        // Swap the names of q1 and q2
        swap(q1, q2);

        return poppedElement;
    }

    // Check if the stack is empty
    bool isEmpty() {
        return q1.empty();
    }
};

int main() {
    Stack stack;

    stack.push(5);
    stack.push(10);
    stack.push(15);

    cout << stack.pop() << endl; // Output: 15
    cout << stack.pop() << endl; // Output: 10
    cout << stack.pop() << endl; // Output: 5

    cout << boolalpha << stack.isEmpty() << endl; // Output: true

    return 0;
}


