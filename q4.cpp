//implementation of circular queue
#include <iostream>
#define MAX_SIZE 5
Using namespace std;
class CircularQueue {
private:
    int* queueArray;
    int front;
    int rear;
    int currentSize;
    int maxSize;

public:
    CircularQueue() {
        queueArray = new int[MAX_SIZE];
        front = -1;
        rear = -1;
        currentSize = 0;
        maxSize = MAX_SIZE;
    }

    ~CircularQueue() {
        delete[] queueArray;
    }

    bool isEmpty() {
        return currentSize == 0;
    }

    bool isFull() {
        return currentSize == maxSize;
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue overflow! Cannot enqueue element " << value << endl;
            return;
        }
        if (front == -1) { 
            front = 0;
        }
        rear = (rear + 1) % maxSize;
        queueArray[rear] = value;
        currentSize++;
        cout << "Enqueued element " << value << endl;
    }

    void dequeue() {
        if (isEmpty()) {
           cout << "Queue underflow! Cannot dequeue element from an empty queue." << endl;
            return;
        }
        int dequeuedValue = queueArray[front];
        if (front == rear) {
            front = -1;
            rear = -1;
        }
        else {
            front = (front + 1) % maxSize;
        }
        currentSize--;
        cout << "Dequeued element: " << dequeuedValue << endl;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return queueArray[front];
    }
};

int main() {
    CircularQueue myQueue;

    myQueue.enqueue(5);
    myQueue.enqueue(10);
    myQueue.enqueue(15);

    cout << "Front element of the queue: " << myQueue.peek() << endl;

    myQueue.dequeue();
    myQueue.dequeue();

    cout << "Is the queue empty? " << (myQueue.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}

