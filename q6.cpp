
#include <iostream>
#include <queue>

class Stack {
private:
    queue<int> q1;
    queue<int> q2;

public:
    void push(int value) {
        q1.push(value);
        cout << "Pushed element: " << value << endl;
    }

    void pop() {
        if (q1.empty()) {
            cout << "Stack underflow! Cannot perform pop operation on an empty stack." << endl;
            return;
        }

        // Move elements from q1 to q2 except the last element
        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }

        // Pop the last element from q1
        int poppedValue = q1.front();
        q1.pop();

        // Swap the queues
        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;

        cout << "Popped element: " << poppedValue << std::endl;
    }

    int top() {
        if (q1.empty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }

        // Move elements from q1 to q2 except the last element
        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }

        // Get the last element from q1
        int topValue = q1.front();

        // Move the element to q2
        q2.push(topValue);

        // Swap the queues
        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;

        return topValue;
    }

    bool isEmpty() {
        return q1.empty();
    }
};

int main() {
    Stack myStack;

    myStack.push(5);
    myStack.push(10);
    myStack.push(15);

    cout << "Top element of the stack: " << myStack.top() << endl;

    myStack.pop();
    myStack.pop();

    cout << "Is the stack empty? " << (myStack.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}

