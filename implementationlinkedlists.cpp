#include <iostream>

// Node structure for the linked list
struct Node {
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// Linked list class
class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    // Insert a new node at the beginning of the linked list
    void insert(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    // Delete a node with a given value from the linked list
    void remove(int value) {
        if (head == nullptr) {
            return;
        }

        // Check if the value to be removed is at the head of the list
        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* curr = head;
        Node* prev = nullptr;

        // Traverse the list to find the node to be deleted
        while (curr != nullptr && curr->data != value) {
            prev = curr;
            curr = curr->next;
        }

        // If the value is found, remove the node
        if (curr != nullptr) {
            prev->next = curr->next;
            delete curr;
        }
    }

    // Print the linked list
    void print() {
        Node* curr = head;
        while (curr != nullptr) {
            std::cout << curr->data << " ";
            curr = curr->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    LinkedList myList;

    // Insert nodes into the linked list
    myList.insert(10);
    myList.insert(20);
    myList.insert(30);
    myList.insert(40);

    // Print the linked list
    std::cout << "Linked List: ";
    myList.print();

    // Delete a node from the linked list
    myList.remove(20);

    // Print the updated linked list
    std::cout << "Updated Linked List: ";
    myList.print();

    return 0;
}

