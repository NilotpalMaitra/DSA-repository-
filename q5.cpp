//dequeu and enqueue of array()
#include <iostream>
#define MAX_SIZE 5
Using namespace std;
class Deque {
private:
    int* dequeArray;
    int front;
    int rear;
    int currentSize;
    int maxSize;

public:
    Deque() {
        dequeArray = new int[MAX_SIZE];
        front = -1;
        rear = -1;
        currentSize = 0;
        maxSize = MAX_SIZE;
    }

    ~Deque() {
        delete[] dequeArray;
    }

    bool isEmpty() {
        return currentSize == 0;
    }

    bool isFull() {
        return currentSize == maxSize;
    }

    void enqueueFront(int value) {
        if (isFull()) {
            cout << "Deque overflow! Cannot enqueue element " << value << " at the front." << endl;
            return;
        }
        if (isEmpty()) {
            front = 0;
            rear = 0;
        }
        else {
            front = (front - 1 + maxSize) % maxSize;
        }
        dequeArray[front] = value;
        currentSize++;
        cout << "Enqueued element " << value << " at the front." << endl;
    }

    void enqueueRear(int value) {
        if (isFull()) {
            std::cout << "Deque overflow! Cannot enqueue element " << value << " at the rear." << std::endl;
            return;
        }
        if (isEmpty()) {
            front = 0;
            rear = 0;
        }
        else {
            rear = (rear + 1) % maxSize;
        }
        dequeArray[rear] = value;
        currentSize++;
        cout << "Enqueued element " << value << " at the rear." << endl;
    }

    void dequeueFront() {
        if (isEmpty()) {
            cout << "Deque underflow! Cannot dequeue element from the front of an empty deque." << endl;
            return;
        }
        int dequeuedValue = dequeArray[front];
        if (front == rear) {
            front = -1;
            rear = -1;
        }
        else {
            front = (front + 1) % maxSize;
        }
        currentSize--;
        cout << "Dequeued element from the front: " << dequeuedValue << endl;
    }

    void dequeueRear() {
        if (isEmpty()) {
            cout << "Deque underflow! Cannot dequeue element from the rear of an empty deque." << endl;
            return;
        }
        int dequeuedValue = dequeArray[rear];
        if (front == rear) {
            front = -1;
            rear = -1;
        }
        else {
            rear = (rear - 1 + maxSize) % maxSize;
        }
        currentSize--;
        cout << "Dequeued element from the rear: " << dequeuedValue << endl;
    }

    int getFront() {
        if (isEmpty()) {
            cout << "Deque is empty!" << endl;
            return -1;
        }
        return dequeArray[front];
    }

    int getRear() {
        if (isEmpty()) {
            cout << "Deque is empty!" << endl;
            return -1;
        }
        return dequeArray[rear];
    }
};

int main() {
    Deque myDeque;

    myDeque.enqueueRear(5);
    myDeque.enqueueRear(10);
    myDeque.enqueueFront(3);

    cout << "Front element of the deque: " << myDeque.getFront() << endl;
    cout << "Rear element of the deque: " << myDeque.getRear() << endl;

    myDeque.dequeueFront();
    myDeque.dequeueRear();

    cout << "Is the deque empty? " << (myDeque.isEmpty() ? "Yes" : "No") <<endl;

    return 0;
}
