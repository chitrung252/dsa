// Stack with Linked List
#include <iostream>

using namespace std;

int top = -1;

struct Node {
    int data;
    Node *next;
};
Node *CreateNode(int data) {
    Node *node = new Node();
    node->data = data;
    node->next = NULL;
    return node;
}

struct Stack {
    Node *head;
};

void CreateStack(Stack &s) {
    s.head = NULL;
}

int IsEmpty(Stack &s) {
    if (s.head == NULL)
        return 1;
    return 0;
}

void Push(Stack &s, int data) {
    Node *node = CreateNode(data);
    if (s.head == NULL) {
        s.head = node;
    } else {
        node->next = s.head;
        s.head = node;
    }
}

int Pop(Stack &s) {

    if (s.head != NULL) {
        Node *node = s.head;
        int data = node->data;

        s.head = node->next;

        delete node;
        return data;
    }
    return 0;
}

Node *GetNode(Stack &s, int data) {
    if (s.head != NULL) {
        Node *node = s.head;
        while (node->next != NULL && node->data == data) {
            node = node->next;
        }
        if (node->data == data) {
            return node;
        }
    }

    return NULL;
}

void Print(Stack l) {
    if (IsEmpty(l)) {
        cout << "Stack is empty" << endl;
    } else {
        Node *node = l.head;
        cout << "[\n";
        while (node != NULL) {
            cout << " " << node->data << ", " << endl;
            node = node->next;
        }
        cout << "]\n";
    }
}

void PrintHead(Stack s) {
    Node *node = s.head;
    if (IsEmpty(s)) {
        cout << "Stack is empty" << endl;
    } else {
        cout << "\nHead: " << node->data << endl;
    }
}

int main() {
    Stack s;
    CreateStack(s);

    Push(s, 1);
    Push(s, 2);
    Push(s, 3);

    Print(s);
    PrintHead(s);
    Node *node1 = GetNode(s, 1);
    Pop(s);
    Pop(s);

    Print(s);
    PrintHead(s);
    return 0;
}
