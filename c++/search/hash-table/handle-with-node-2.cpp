#include <iostream>

using namespace std;

#define MAX 20

class Node {
public:
    int key;
    int data;
    Node *next;
    Node(int _key, int _data) {
        this->data = _data;
        this->key = _key;
    }
    ~Node();
};

typedef Node *HashTable[MAX];

void addTail(HashTable *&node, int key, int val);
void initHashTable(HashTable &ht);
int hashKey(int key);
Node *searchNode(int val);
void removeNode(int val);
void insertNode(HashTable &ht, int key, int data);

void print(HashTable ht);

void initHashTable(HashTable &ht) {
    for (int i = 0; i < MAX; i++) {
        ht[i] = NULL;
    }
}

int hashKey(int key) {
    return key % MAX;
}

void addTail(Node *&node, int key, int val) {

    Node *newNode = new Node(key, val);

    if (node == NULL) {

        node = newNode;
    } else {
        Node *currentNode = node;
        while (currentNode != NULL && currentNode->next != NULL) {
            currentNode = currentNode->next;
        }
        node->next = newNode;
    }
}

void insertNode(HashTable &ht, int key, int data) {
    int index = hashKey(key);

    addTail(ht[index], index, data);
}

void print(HashTable ht) {
    for (int i = 0; i < MAX; i++) {
        if (ht[i] != NULL) {
            cout << "Bucket " << i << " :" << ht[i]->data << endl;

        } else {
            cout << "Bucket " << i << " :" << ht[i] << endl;
        }
    }
}
Node *searchNode(HashTable ht, int key) {
    int index = hashKey(key);
    Node *node = ht[index];
    while (node != NULL && node->key != key) {
        node = node->next;
    }
    return node;
}
int main() {
    HashTable ht;
    initHashTable(ht);
    insertNode(ht, 0, 0);
    insertNode(ht, 1, 10);
    insertNode(ht, 2, 20);
    insertNode(ht, 3, 30);
    insertNode(ht, 4, 40);
    insertNode(ht, 5, 50);

    print(ht);
    Node *node = searchNode(ht, 5);
    if (node) {
        cout << "Node found: " << node->data << endl;
    } else {
        cout << "Node  not found: " << endl;
    }

    return 0;
}
