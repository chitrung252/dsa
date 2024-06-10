#include <iostream>

using namespace std;

struct Node {
    int key;
    int data;
    Node *next;
    Node *previous;
};

Node *CreateNode(int key, int data) {
    Node *node = new Node();
    node->data = data;
    node->key = key;
    node->next = NULL;
    node->previous = NULL;
    return node;
};

struct CLinkedList {
    Node *head;
    Node *tail;
};

void CreateList(CLinkedList &l) {
    l.head = NULL;
    l.tail = NULL;
}

bool isEmpty(CLinkedList l) {
    return l.head == NULL;
}

void AddHead(CLinkedList &l, Node *node) {
    if (isEmpty(l)) {
        l.head = node;
        l.head->next = node;
    } else {
        l.head->previous = node;
        node->next = l.head;
        l.head = node;
        node->previous = l.tail;
        l.tail->next = node;
    }
}

void AddTail(CLinkedList &l, Node *node) {
    if (isEmpty(l)) {
        AddHead(l, node);
        l.tail = node;
    } else {
        l.tail->next = node;
        node->previous = l.tail;
        node->next = l.head;
        l.tail = node;
        l.head->previous = node;
    }
}

// O(n)
void PrintForward(CLinkedList l) {
    if (!isEmpty(l)) {
        Node *nodeHead = l.head;
        Node *node = l.head;
        cout << "[";

        while (node->next != nodeHead) {
            cout << "(" << node->key << "," << node->data << ") \n";
            cout << "Node Previous:" << node->previous->data << endl;
            node = node->next;
        };
        cout << "( " << l.tail->key << "," << l.tail->data << ") ";
        cout << "]\n";
    }
}

void PrintTailAndHead(CLinkedList l) {
    cout << "\nHead: " << l.head->data << endl;
    cout << "\nHead Node Prev: " << l.head->previous->data << endl;
    cout << "\nHead Node Next: " << l.head->next->data << endl;

    cout << "Tail: " << l.tail->data << endl;

    cout << "\nTail Node Prev: " << l.tail->previous->data << endl;
    cout << "\nTail Node Next: " << l.tail->next->data << endl;
}

Node *SearchForward(CLinkedList &l, int data) {
    if (l.head != NULL) {
        Node *node = l.head;
        while (node->next != l.head && node->data != data) {
            node = node->next;
        }
        if (node->data == data) {
            return node;
        }
    }
    return NULL;
}

void DeleteNode(CLinkedList &l, int data) {
    if (l.head != NULL) {
        Node *node = SearchForward(l, data);
        node->previous->next = node->next;
        node->next->previous = node->previous;
        if (node == l.head) {
            l.head = node->next;
        } else if (node == l.tail) {
            l.tail = node->previous;
        }
        // delete node;
    }
}

int main() {
    CLinkedList l;
    CreateList(l);

    Node *node0 = CreateNode(0, 0);
    AddTail(l, node0);
    for (int i = 1; i <= 9; i++) {
        Node *node = CreateNode(i + 10, i);
        AddTail(l, node);
    }

    Node *node10 = CreateNode(10, 10);
    AddHead(l, node10);

    // Node *found = SearchForward(l, 0);

    DeleteNode(l, 0);
    DeleteNode(l, 10);
    DeleteNode(l, 9);

    PrintForward(l);
    PrintTailAndHead(l);
    return 0;
}