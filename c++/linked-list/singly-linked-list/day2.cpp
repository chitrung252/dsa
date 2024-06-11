

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

void CreateLinkedList(LinkedList &l) {
    l.head = NULL;
    l.tail = NULL;
}

void PrintList(LinkedList l) {
    if (l.head != NULL) {
        Node *node = l.head;
        while (node != NULL) {
            cout << "Node: " << node->data << "\n";
            node = node->next;
        }
    }
}

Node *Search(LinkedList l, int number) {
    if (l.head != NULL) {
        Node *node = l.head;
        while (node->data != number) {
            node = node->next;
        }
        return node;
    }
    return NULL;
}

void AddTail(LinkedList &l, Node *node) {
    if (l.head == NULL) {
        l.head = node;
        l.tail = node;
    } else {
        l.tail->next = node;
        l.tail = node;
    }
};

void AddHead(LinkedList &l, Node *node) {
    if (l.head == NULL) {
        l.head = node;
        l.tail = node;
    } else {
        node->next = l.head;
        l.head = node;
    }
}

void InsertAfterNode(LinkedList &l, Node *node, Node *newNode) {
    if (l.tail == node) {
        AddTail(l, newNode);
    } else {
        newNode->next = node->next;
        node->next = newNode;
    }
}

void RemoveHead(LinkedList &l) {
    if (l.head != NULL) {
        Node *head = l.head;
        l.head = l.head->next;
        delete head;
        if (l.head == NULL) {
            l.tail = NULL;
        }
    }
}

Node *GetNode(LinkedList &l, int index) {
    if (l.head != NULL) {
        Node *node = l.head;
        int i = 0;
        while (node != NULL && index != i) {
            node = node->next;
            i++;
        }
        if (node != NULL && index == i) {
            return node;
        }
        return NULL;
    }

    return NULL;
}

void RemoveAnyNode(LinkedList &l, int number) {
    if (l.head != NULL) {
        if (l.head->next != NULL) {

            Node *nodePrevious = l.head;

            while (nodePrevious->next->data != number) {
                nodePrevious = nodePrevious->next;
            }
            Node *nodeCurrent = Search(l, number);
            nodePrevious->next = nodeCurrent->next;
            if (l.tail == nodeCurrent) {
                l.tail = nodePrevious;
            }
            delete nodeCurrent;
        } else {
            delete l.head;
            l.head = NULL;
            l.tail = NULL;
        }
    }
}

int Length(LinkedList l) {
    int count = 0;
    Node *node = l.head;
    while (node != NULL) {
        count++;
        node = node->next;
    }
    return count;
}

void DestroyList(LinkedList &l) {
    Node *node = l.head;
    while (node != NULL) {
        RemoveHead(l);
        node = l.head;
    }
    l.tail = NULL;
}

int main() {
    LinkedList list;
    CreateLinkedList(list);
    for (int i = 0; i < 10; i++) {
        Node *node = CreateNode(i);
        AddTail(list, node);
    }

    Node *node = Search(list, 6);
    Node *newNode100 = CreateNode(100);
    InsertAfterNode(list, node, newNode100);

    Node *newNode101 = CreateNode(101);
    InsertAfterNode(list, newNode100, newNode101);

    Node *newNode102 = CreateNode(102);
    AddHead(list, newNode102);
    RemoveHead(list);
    RemoveHead(list);
    RemoveAnyNode(list, 9);
    PrintList(list);
    cout << "\nNode head: " << list.head->data << endl;
    cout << "Node tail: " << list.tail->data << endl;
    int index = 9;
    Node *nodeGetterByIndex = GetNode(list, index);
    if (nodeGetterByIndex) {
        cout << "node by index " << index << " have data: " << nodeGetterByIndex->data << endl;
    } else {
        cout << "node at index: " << index << " does not exist" << endl;
    }
    int lengthLinkedList = Length(list);
    cout << "\nLinked List Length: " << lengthLinkedList << endl;

    cout << "Destroy List..." << endl;

    DestroyList(list);
    int lengthLinkedListEmpty = Length(list);
    cout << "\nLinked List Length: " << lengthLinkedListEmpty << endl;
    return 0;
};