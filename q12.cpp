
#include <iostream>

// Node structure for BST
struct Node {
    int key;
    Node* left;
    Node* right;

    Node(int value) {
        key = value;
        left = NULL;
        right = NULL;
    }
};

// Class for BST
class BinarySearchTree {
private:
    Node* root;
 
    // Helper function to insert a node recursively
    Node* insertRecursive(Node* root, int key) {
        if (root == NULL) {
            return new Node(key);
        }

        if (key < root->key) {
            root->left = insertRecursive(root->left, key);
        } else if (key > root->key) {
            root->right = insertRecursive(root->right, key);
        }

        return root;
    }

    // Helper function to find the minimum key recursively
    Node* findMinRecursive(Node* root) {
        if (root == NULL || root->left == NULL) {
            return root;
        }

        return findMinRecursive(root->left);
    }

    // Helper function to find the maximum key recursively
    Node* findMaxRecursive(Node* root) {
        if (root == NULL || root->right == NULL) {
            return root;
        }

        return findMaxRecursive(root->right);
    }

    // Helper function to search for a given key recursively
    Node* searchRecursive(Node* root, int key) {
        if (root == NULL || root->key == key) {
            return root;
        }

        if (key < root->key) {
            return searchRecursive(root->left, key);
        }

        return searchRecursive(root->right, key);
    }

    // Helper function to find the predecessor of a node recursively
    Node* findPredecessorRecursive(Node* root, int key) {
        Node* current = searchRecursive(root, key);

        if (current == NULL) {
            return NULL;
        }

        if (current->left != NULL) {
            return findMaxRecursive(current->left);
        } else {
            Node* predecessor = NULL;
            Node* ancestor = root;

            while (ancestor != current) {
                if (current->key > ancestor->key) {
                    predecessor = ancestor;
                    ancestor = ancestor->right;
                } else {
                    ancestor = ancestor->left;
                }
            }

            return predecessor;
        }
    }

    // Helper function to find the successor of a node recursively
    Node* findSuccessorRecursive(Node* root, int key) {
        Node* current = searchRecursive(root, key);

        if (current == NULL) {
            return NULL;
        }

        if (current->right != NULL) {
            return findMinRecursive(current->right);
        } else {
            Node* successor = NULL;
            Node* ancestor = root;

            while (ancestor != current) {
                if (current->key < ancestor->key) {
                    successor = ancestor;
                    ancestor = ancestor->left;
                } else {
                    ancestor = ancestor->right;
                }
            }

            return successor;
        }
    }

    // Helper function to delete a node with a given key recursively
    Node* deleteNodeRecursive(Node* root, int key) {
        if (root == NULL) {
            return NULL;
        }

        if (key < root->key) {
            root->left = deleteNodeRecursive(root->left, key);
        } else if (key > root->key) {
            root->right = deleteNodeRecursive(root->right, key);
        } else {
            if (root->left == NULL) {
                Node* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == NULL) {
                Node* temp = root->left;
                delete root;
                return temp;
            }

            Node* successor = findMinRecursive(root->right);
            root->key = successor->key;
            root->right = deleteNodeRecursive(root->right, successor->key);
        }

        return root;
    }

public:
    BinarySearchTree() {
        root = nullptr;
    }

    // Insert a key into the BST
    void insert(int key) {
        root = insertRecursive(root, key);
    }

    // Find the minimum key in the BST
    int findMin() {
        Node* minNode = findMinRecursive(root);
        if (minNode != NULL) {
            return minNode->key;
        }
        return -1; // Assuming -1 represents an empty tree
    }

    // Find the maximum key in the BST
    int findMax() {
        Node* maxNode = findMaxRecursive(root);
        if (maxNode != NULL) {
            return maxNode->key;
        }
        return -1; // Assuming -1 represents an empty tree
    }

    // Search for a given key in the BST
    bool search(int key) {
        Node* foundNode = searchRecursive(root, key);
        return foundNode != NULL;
    }

    // Find the predecessor of a node with a given key
    int findPredecessor(int key) {
        Node* predecessor = findPredecessorRecursive(root, key);
        if (predecessor != NULL) {
            return predecessor->key;
        }
        return -1; // Assuming -1 represents no predecessor
    }

    // Find the successor of a node with a given key
    int findSuccessor(int key) {
        Node* successor = findSuccessorRecursive(root, key);
        if (successor != NULL) {
            return successor->key;
        }
        return -1; // Assuming -1 represents no successor
    }

    // Delete a node with a given key from the BST
    void deleteNode(int key) {
        root = deleteNodeRecursive(root, key);
    }
};

int main() {
    BinarySearchTree bst;

    // Create the BST by considering the keys in a given order
    bst.insert(50);
    bst.insert(30);
    bst.insert(20);
    bst.insert(40);
    bst.insert(70);
    bst.insert(60);
    bst.insert(80);

    cout << "Minimum key: " << bst.findMin() << endl;  // Output: Minimum key: 20
    cout << "Maximum key: " << bst.findMax() << endl;  // Output: Maximum key: 80

    int searchKey = 60;
    if (bst.search(searchKey)) {
        cout << searchKey << " found in the BST." << endl;  // Output: 60 found in the BST.
    } else {
        cout << searchKey << " not found in the BST." << endl;
    }

    int predecessorKey = 50;
    int predecessor = bst.findPredecessor(predecessorKey);
    if (predecessor != -1) {
        cout << "Predecessor of " << predecessorKey << ": " << predecessor << endl;  // Output: Predecessor of 50: 40
    } else {
        cout << "No predecessor found for " << predecessorKey << endl;
    }

    int successorKey = 30;
    int successor = bst.findSuccessor(successorKey);
    if (successor != -1) {
        cout << "Successor of " << successorKey << ": " << successor << endl;  // Output: Successor of 30: 40
    } else {
        cout << "No successor found for " << successorKey << endl;
    }

    int deleteKey = 30;
    bst.deleteNode(deleteKey);
    cout << "Deleted node with key " << deleteKey << endl;

    return 0;
}

