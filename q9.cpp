#include <iostream>
Using namespace std;
// Node structure for single linked list
struct Node {
    int data;
    Node* next;
};

// Class for single linked list
class SingleLinkedList {
private:
    Node* head;

public:
    SingleLinkedList() {
        head = NULL;
    }

    // Insert a new node at the beginning of the list
    void insert(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = head;
        head = newNode;
    }

    // Display the contents of the list
    void display() {
        Node* current = head;
        while (current != NULL) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

// Node structure for double linked list
struct DNode {
    int data;
    DNode* prev;
    DNode* next;
};

// Class for double linked list
class DoubleLinkedList {
private:
    DNode* head;

public:
    DoubleLinkedList() {
        head = NULL;
    }

    // Insert a new node at the beginning of the list
    void insert(int data) {
        DNode* newNode = new DNode();
        newNode->data = data;
        newNode->prev = NULL;
        newNode->next = head;

        if (head != NULL) {
            head->prev = newNode;
        }

        head = newNode;
    }

    // Display the contents of the list
    void display() {
        DNode* current = head;
        while (current != NULL) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    // Single linked list
    SingleLinkedList sList;
    sList.insert(3);
    sList.insert(7);
    sList.insert(9);
    sList.display();  // Output: 9 7 3

    // Double linked list
    DoubleLinkedList dList;
    dList.insert(5);
    dList.insert(2);
    dList.insert(8);
    dList.display();  // Output: 8 2 5

    return 0;
}

