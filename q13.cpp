
#include <iostream>

// Node structure for AVL tree
struct Node {
    int key;
    int height;
    Node* left;
    Node* right;

    Node(int value) {
        key = value;
        height = 1;
        left = nullptr;
        right = nullptr;
    }
};

// Function to get the height of a node
int getHeight(Node* node) {
    if (node == nullptr) {
        return 0;
    }
    return node->height;
}

// Function to get the balance factor of a node
int getBalanceFactor(Node* node) {
    if (node == nullptr) {
        return 0;
    }
    return getHeight(node->left) - getHeight(node->right);
}

// Function to update the height of a node
void updateHeight(Node* node) {
    if (node == nullptr) {
        return;
    }
    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
}

// Function to perform a right rotation
Node* rotateRight(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    updateHeight(y);
    updateHeight(x);

    return x;
}

// Function to perform a left rotation
Node* rotateLeft(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    updateHeight(x);
    updateHeight(y);

    return y;
}

// Function to insert a key into the AVL tree
Node* insert(Node* root, int key) {
    // Perform standard BST insertion
    if (root == nullptr) {
        return new Node(key);
    }

    if (key < root->key) {
        root->left = insert(root->left, key);
    } else if (key > root->key) {
        root->right = insert(root->right, key);
    } else {
        // Duplicate keys are not allowed in AVL tree
        return root;
    }

    // Update the height of the current node
    updateHeight(root);

    // Check the balance factor and perform rotations if necessary
    int balanceFactor = getBalanceFactor(root);

    // Left Left case
    if (balanceFactor > 1 && key < root->left->key) {
        return rotateRight(root);
    }

    // Right Right case
    if (balanceFactor < -1 && key > root->right->key) {
        return rotateLeft(root);
    }

    // Left Right case
    if (balanceFactor > 1 && key > root->left->key) {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    // Right Left case
    if (balanceFactor < -1 && key < root->right->key) {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}

// Function to find the node with the minimum key value in an AVL tree
Node* findMinNode(Node* root) {
    if (root == nullptr || root->left == nullptr) {
        return root;
    }
    return findMinNode(root->left);
}

// Function to delete a key from the AVL tree
Node* deleteNode(Node* root, int key) {
    if (root == nullptr) {
        return root;
    }

    if (key < root->key) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->key) {
        root->right = deleteNode(root->right, key);
    } else {
        // Node to be deleted found

        // Node with only one child or no child
        if (root->left == nullptr || root->right == nullptr) {
            Node* temp = root->left ? root->left : root->right;

            // No child case
            if (temp == nullptr) {
                temp = root;
                root = nullptr;
            } else { // One child case
                *root = *temp; // Copy the contents of the non-empty child
            }

            delete temp;
        } else {
            // Node with two children
            Node* temp = findMinNode(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }

    // If the tree had only one node, return
    if (root == nullptr) {
        return root;
    }

    // Update the height of the current node
    updateHeight(root);

    // Check the balance factor and perform rotations if necessary
    int balanceFactor = getBalanceFactor(root);

    // Left Left case
    if (balanceFactor > 1 && getBalanceFactor(root->left) >= 0) {
        return rotateRight(root);
    }

    // Left Right case
    if (balanceFactor > 1 && getBalanceFactor(root->left) < 0) {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    // Right Right case
    if (balanceFactor < -1 && getBalanceFactor(root->right) <= 0) {
        return rotateLeft(root);
    }

    // Right Left case
    if (balanceFactor < -1 && getBalanceFactor(root->right) > 0) {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}

// Function to print the AVL tree in in-order traversal
void printInOrder(Node* root) {
    if (root != nullptr) {
        printInOrder(root->left);
        std::cout << root->key << " ";
        printInOrder(root->right);
    }
}

int main() {
    Node* root = nullptr;

    // Construct the AVL tree
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    std::cout << "AVL tree (in-order traversal): ";
    printInOrder(root);
    std::cout << std::endl;

    // Delete a key from the AVL tree
    root = deleteNode(root, 30);

    std::cout << "AVL tree after deleting key 30 (in-order traversal): ";
    printInOrder(root);
    std::cout << std::endl;

    return 0;
}

