
#include <iostream>
Using namespace std;
// Node structure for queue
struct Node {
    int data;
    Node* next;
};

// Class for queue
class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() {
        front = NULL;
        rear = NULL;
    }

    // Enqueue an element into the queue
    void enqueue(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = NULL;

        if (isEmpty()) {
            front = newNode;
            rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    // Dequeue an element from the queue
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
        } else {
            Node* temp = front;
            front = front->next;

            if (front == NULL) {
                rear = NULL;
            }

            delete temp;
        }
    }

    // Check if the queue is empty
    bool isEmpty() {
        return front == NULL;
    }

    // Display the front element of the queue
    void displayFront() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
        } else {
            cout << "Front element: " << front->data << endl;
        }
    }
};

int main() {
    Queue queue;

    queue.enqueue(5);
    queue.enqueue(10);
    queue.enqueue(15);
    queue.displayFront();  // Output: Front element: 5

    queue.dequeue();
    queue.displayFront();  // Output: Front element: 10

    queue.dequeue();
    queue.displayFront();  // Output: Front element: 15

    queue.dequeue();
    queue.displayFront();  // Output: Queue is empty.

    return 0;
}

