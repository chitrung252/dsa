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
};

struct SinglyLinkedList {
    Node *head;
    Node *tail;
};

void CreateLinkedList(SinglyLinkedList *l) {
    l->head = NULL;
    l->tail = NULL;
}

void AddTail(SinglyLinkedList *l, Node *node) {
    if (l->head == NULL) {
        l->head = node;
        l->tail = node;
    } else {
        l->tail->next = node;
        l->tail = node;
    }
}

void AddHead(SinglyLinkedList *l, Node *node) {
    if (l->head == NULL) {
        l->head = node;
        l->tail = node;
    } else {
        node->next = l->head;
        l->head = node;
    }
}

// O(n)
Node *Search(SinglyLinkedList *l, int data) {
    if (l->head != NULL) {

        Node *node = l->head;
        while (node->data != data) {
            node = node->next;
        }
        return node;
    }
    return NULL;
}

void Print(SinglyLinkedList *l) {
    if (l->head != NULL) {
        Node *node = l->head;
        while (node != NULL) {
            cout << "Node: " << node->data << endl;
            node = node->next;
        }
    }
}

void PrintHeadAndTail(SinglyLinkedList *l) {
    cout << "Head:" << l->head->data << endl;
    cout << "Tail: " << l->tail->data << endl;
}

// O(1)
void InsertAfter(SinglyLinkedList *l, Node *node, Node *newNode) {
    if (l->head != NULL) {
        if (l->tail == node) {
            AddTail(l, newNode);
        } else {
            newNode->next = node->next;
            node->next = newNode;
        }
    }
}

// O(n)
void UpdateNode(SinglyLinkedList *l, Node *node, Node *newNode) {
    if (l->head != NULL) {

        if (l->head == node) {
            l->head = newNode;
            newNode->next = node->next;
        } else {
            Node *nodeHead = l->head;

            while (nodeHead->next != node) {
                nodeHead = nodeHead->next;
            }
            nodeHead->next = newNode;
            newNode->next = node->next;
            if (l->tail == node) {
                l->tail = newNode;
            }
        }

        delete node;
    }
}

void RemoveNode(SinglyLinkedList *l, Node *node) {
    if (l->head != NULL) {
        if (l->head == node) {
            l->head = l->head->next;
        } else {
            Node *nodeHead = l->head;

            while (nodeHead->next != node) {
                nodeHead = nodeHead->next;
            }
            nodeHead->next = node->next;
            if (l->tail == node) {
                l->tail = nodeHead;
            }
        }

        delete node;
    }
}

int main() {
    SinglyLinkedList *l = new SinglyLinkedList();
    CreateLinkedList(l);

    for (int i = 0; i < 10; i++) {
        Node *node = CreateNode(i);
        AddTail(l, node);
    }

    Node *node20 = CreateNode(20);
    // AddHead(l, node20);

    Node *found = Search(l, 0);

    InsertAfter(l, found, node20);

    Node *node21 = CreateNode(21);
    UpdateNode(l, found, node21);

    RemoveNode(l, node21);
    Print(l);
    PrintHeadAndTail(l);
    Node *found9 = Search(l, 9);
    RemoveNode(l, found9);

    Print(l);
    PrintHeadAndTail(l);
}