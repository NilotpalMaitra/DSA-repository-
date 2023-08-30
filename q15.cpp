#include <iostream>
#include <list>
#include <vector>

// Separate Chaining Hash Table
class SeparateChainingHash {
private:
    int tableSize;
    vector<list<int>> table;

    // Hash function to map a key to an index
    int hashFunction(int key) {
        return key % tableSize;
    }

public:
    SeparateChainingHash(int size) {
        tableSize = size;
        table.resize(tableSize);
    }

    // Insert a key into the hash table
    void insert(int key) {
        int index = hashFunction(key);
        table[index].push_back(key);
    }

    // Search for a key in the hash table
    bool search(int key) {
        int index = hashFunction(key);
        for (int k : table[index]) {
            if (k == key) {
                return true;
            }
        }
        return false;
    }

    // Delete a key from the hash table
    void remove(int key) {
        int index = hashFunction(key);
        table[index].remove(key);
    }
};

// Open Addressing Hash Table
class OpenAddressingHash {
private:
    int tableSize;
    vector<int> table;

    // Hash function to map a key to an index
    int hashFunction(int key) {
        return key % tableSize;
    }

public:
    OpenAddressingHash(int size) {
        tableSize = size;
        table.resize(tableSize, -1);
    }

    // Insert a key into the hash table
    void insert(int key) {
        int index = hashFunction(key);

        while (table[index] != -1) {
            index = (index + 1) % tableSize;
        }

        table[index] = key;
    }

    // Search for a key in the hash table
    bool search(int key) {
        int index = hashFunction(key);

        int count = 0;
        while (table[index] != -1 && count < tableSize) {
            if (table[index] == key) {
                return true;
            }
            index = (index + 1) % tableSize;
            count++;
        }

        return false;
    }

    // Delete a key from the hash table
    void remove(int key) {
        int index = hashFunction(key);

        int count = 0;
        while (table[index] != -1 && count < tableSize) {
            if (table[index] == key) {
                table[index] = -1;
                return;
            }
            index = (index + 1) % tableSize;
            count++;
        }
    }
};

int main() {
    // Separate Chaining Hashing
    SeparateChainingHash separateChainingHash(10);

    separateChainingHash.insert(5);
    separateChainingHash.insert(15);
    separateChainingHash.insert(25);

    cout << "Separate Chaining Hashing:" << endl;
    cout << "5 is " << (separateChainingHash.search(5) ? "found" : "not found") << endl;
    cout << "10 is " << (separateChainingHash.search(10) ? "found" : "not found") << endl;

    separateChainingHash.remove(15);

    cout << "After removing 15, 15 is " << (separateChainingHash.search(15) ? "found" : "not found") << endl;

  cout << endl;

    // Open Addressing Hashing
    OpenAddressingHash openAddressingHash(10);

    openAddressingHash.insert(5);
    openAddressingHash.insert(15);
    openAddressingHash.insert(25);

    cout << "Open Addressing Hashing:" << std::endl;
    cout << "5 is " << (openAddressingHash.search(5) ? "found" : "not found") << endl;
    cout << "10 is " << (openAddressingHash.search(10) ? "found" : "not found") << endl;

    openAddressingHash.remove(15);

    cout << "After removing 15, 15 is " << (openAddressingHash.search(15) ? "found" : "not found") <<  endl;

    return 0;
}
