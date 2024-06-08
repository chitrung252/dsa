#include <iostream>

using namespace std;

struct Node {
    int data;
    Node *next;
    Node *previous;
};

Node *CreateNode(int data) {
    Node *node = new Node();
    node->data = data;
    node->next = NULL;
    node->previous = NULL;
    return node;
};

struct DLinkedList {
    Node *head;
    Node *tail;
};

void CreateDoublyLinkedList(DLinkedList &l) {
    l.head = NULL;
    l.tail = NULL;
};

// O(n)
void PrintForward(DLinkedList l) {
    if (l.head != NULL) {
        Node *node = l.head;
        cout << "[";
        while (node != NULL) {
            cout << node->data << " ";
            node = node->next;
        }
        cout << "]\n";
    }
}

// O(n)
void PrintBackward(DLinkedList l) {
    if (l.head != NULL) {
        Node *node = l.tail;
        cout << "[";
        while (node != NULL) {
            cout << node->data << " ";
            node = node->previous;
        }
        cout << "]\n";
    }
}

void PrintTailAndHead(DLinkedList l) {
    cout << "\nHead: " << l.head->data << endl;
    cout << "Tail: " << l.tail->data << endl;
}

void AddTail(DLinkedList &l, Node *node) {
    if (l.head == NULL) {
        l.head = node;
        l.tail = node;
    } else {
        node->previous = l.tail;
        l.tail->next = node;
        l.tail = node;
    }
}

void AddHead(DLinkedList &l, Node *node) {
    if (l.head == NULL) {
        l.head = node;
        l.tail = node;
    } else {
        l.head->previous = node;
        node->next = l.head;
        l.head = node;
    }
}

Node *SearchForward(DLinkedList &l, int data) {
    if (l.head != NULL) {
        Node *node = l.head;
        while (node != NULL && node->data != data) {
            node = node->next;
        }
        if (node->data == data) {
            return node;
        }
    }
    return NULL;
}

void InsertAfterNode(DLinkedList &l, Node *node, Node *newNode) {
    if (l.head != NULL) {

        newNode->previous = node;
        newNode->next = node->next;
        node->next = newNode;

        if (l.tail == node) {
            l.tail = newNode;
        }
    }
}

void DeleteNode(DLinkedList &l, Node *node) {
    if (l.head != NULL) {

        if (node == l.head) {
            l.head = node->next;
            node->next->previous = NULL;
        } else if (node == l.tail) {
            l.tail = node->previous;
            node->previous->next = NULL;
        } else {
            node->previous->next = node->next;
            node->next->previous = node->previous;
        }

        delete node;
    }
}

int main() {
    DLinkedList l;
    CreateDoublyLinkedList(l);

    for (int i = 0; i < 10; i++) {
        Node *node = CreateNode(i);
        AddTail(l, node);
    }

    PrintBackward(l);
    cout << "\n";

    Node *node11 = CreateNode(11);
    AddHead(l, node11);

    PrintBackward(l);

    Node *found = SearchForward(l, 9);

    Node *node20 = CreateNode(20);
    InsertAfterNode(l, node11, node20);

    Node *node7 = SearchForward(l, 7);

    DeleteNode(l, node7);

    PrintForward(l);
    PrintTailAndHead(l);
    return 0;
}