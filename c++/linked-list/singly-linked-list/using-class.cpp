// Base on LeetCode
// https://leetcode.com/explore/learn/card/linked-list/209/singly-linked-list/1290/

#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

class LinkedList {
private:
    Node *head;
    Node *tail;
    // Constraints:  0 <= index, val <= 1000
    void _validateVal(int val) {
        if (val < 0 || val > 1000) {
            cerr << "range val between [0, 1000]" << endl;
            exit(EXIT_FAILURE);
        }
    }

    void _validateIndex(int index) {
        int length = this->length();
        if (index > length - 1) {
            cerr << "index out of bound linked list" << endl;
            exit(EXIT_FAILURE);
        }
    }

public:
    LinkedList() {
        this->head = NULL;
        this->tail = NULL;
    }

    int length() {
        int count = 0;
        Node *node = head;
        while (node != NULL) {
            node = node->next;
            count++;
        }
        return count;
    }

    int get(int index) {
        if (head != NULL) {
            Node *node = head;
            int countIdx = 0;
            while (node != NULL && countIdx != index) {
                node = node->next;
                countIdx++;
            }
            if (node != NULL && countIdx == index) {
                return node->data;
            }
        }
        return -1;
    }

    Node *getNode(int index) {
        if (head != NULL) {
            Node *node = head;
            int countIdx = 0;
            while (node != NULL && countIdx != index) {
                node = node->next;
                countIdx++;
            }
            return node;
        }
        return NULL;
    }

    // Add a node of value val before the first element of the linked list.
    // After the insertion, the new node will be the first node of the linked list.
    void addAtHead(int val) {
        _validateVal(val);
        Node *node = new Node(val);
        if (head == NULL) {
            head = node;
            tail = node;
        } else {
            node->next = head;
            head = node;
        }
    }

    // Append a node of value val as the last element of the linked list.
    void addAtTail(int val) {
        _validateVal(val);
        if (head == NULL) {
            this->addAtHead(val);
        } else {
            Node *node = new Node(val);
            tail->next = node;
            tail = node;
        }
    }

    // Add a node of value val before the index^th node in the linked list. If index
    // equals the length of the linked list, the node will be appended to the end of the linked list.
    // If index is greater than the length, the node will not be inserted.
    void addAtIndex(int index, int val) {
        _validateVal(val);
        int length = this->length();
        if (index > length) {
            return;
        }

        if (index == 0) {
            this->addAtHead(val);
        } else if (index == length) {
            this->addAtTail(val);
        } else {
            int countIdx = 0;
            Node *nodePrevious = getNode(index - 1);
            Node *nodeCurrent = getNode(index);

            if (nodePrevious == NULL || nodeCurrent == NULL) {
                cerr << "Node doesnt exist" << endl;
                exit(EXIT_FAILURE);
            }

            Node *newNode = new Node(val);
            newNode->next = nodeCurrent;
            nodePrevious->next = newNode;
        }
    }

    void deleteAtIndex(int index) {
        if (head == NULL) {
            cerr << "Linked is empty" << endl;
            exit(EXIT_FAILURE);
        }
        int length = this->length();
        if (index > length - 1) {
            return;
        }
        Node *nodePrevious, *nodeCurrent, *nodeNext;

        if (index == 0) {
            nodeCurrent = head;
            head = head->next;
        } else if (index == length - 1) {
            nodePrevious = getNode(index - 1);
            nodeCurrent = getNode(index);
            nodePrevious->next = NULL;
            tail = nodePrevious;
        } else {
            nodePrevious = getNode(index - 1);
            nodeNext = getNode(index + 1);
            nodeCurrent = getNode(index);
            nodePrevious->next = nodeNext;
        }

        delete nodeCurrent;
    }

    void print() {
        if (head != NULL) {
            Node *node = head;
            cout << "[ ";
            while (node != NULL) {
                if (node->next == NULL) {
                    cout << node->data << " ";
                } else {
                    cout << node->data << ", ";
                }
                node = node->next;
            }

            cout << "]" << endl;
        }
    }

    void printHeadTail() {
        if (head != NULL) {
            cout << "Head has data: " << head->data << endl;
            cout << "Tail has data: " << tail->data << endl;
        }
    }
};

int main() {
    LinkedList *list = new LinkedList();
    list->addAtHead(4);
    cout << "get index 1 has value: " << list->get(1) << endl;
    // list->addAtTail(3);
    // list->addAtIndex(1, 2);
    // cout << "get index 1 has value: " << list->get(1) << endl;

    // cout << "get index 1 has value: " << list->get(1) << endl;
    list->print();
    int lengthList = list->length();
    cout << "Length: " << lengthList << endl;
    list->printHeadTail();

    return 0;
}