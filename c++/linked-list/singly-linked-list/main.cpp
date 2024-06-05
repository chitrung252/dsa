#include <iostream>

using namespace std;

struct Node {
    int data;
    Node *next;
};

Node *CreateNode(int init_data) {
    Node *node = new Node();
    node->data = init_data;
    node->next = NULL;
    return node;
}

struct LinkedList {
    Node *head;
    Node *tail;
};

void CreateList(LinkedList &l) {
    l.head = NULL;
    l.tail = NULL;
}

void AddTail(LinkedList &l, Node *node) {
    bool checkHead = l.head == NULL ? true : false;

    // cout << " head: " << checkHead << endl;

    if (l.head == NULL) {
        l.head = node;
        l.tail = node;
    } else {
        l.tail->next = node;
        l.tail = node;
    }
}

void AddHead(LinkedList &l, Node *node) {

    if (l.head == NULL) {
        l.head = node;
        l.tail = node;
    } else {
        node->next = l.head;
        l.head = node;
    }
}

void PrintList(LinkedList l) {
    if (l.head != NULL) {
        Node *node = l.head;
        while (node != NULL) {
            cout << node->data << '\n';
            node = node->next;
        }
    }
}

void InsertAfterNode(LinkedList &l, Node *node, Node *newNode) {
    if (node->next != NULL) {
        newNode->next = node->next;
        node->next = newNode;
    } else {
        AddTail(l, newNode);
    }
}

Node *Search(LinkedList l, int x) {
    Node *node = l.head;
    while (node != NULL && node->data != x)
        node = node->next;
    if (node != NULL)
        return node;
    return NULL;
}

int main() {
    LinkedList list;
    CreateList(list);

    Node *node;
    for (auto i = 1; i <= 10; i++) {
        // Create new node with init data is i
        node = CreateNode(i);

        // Add node to head
        // List that is added node by AddHead will be reversed
        // AddHead(list, node);

        // Add node to Tail
        AddTail(list, node);
    }
    Node *nodeHead = CreateNode(11);
    AddTail(list, nodeHead);

    Node *nodeInsert = CreateNode(12);
    Node *search = Search(list, 1);
    InsertAfterNode(list, search, nodeInsert);

    PrintList(list);
}
