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

class Queue {
public:
    Node *head;
    Node *tail;
    Queue() {
        this->head = NULL;
        this->tail = NULL;
    }
    void print() {
        if (head != NULL) {
            Node *node = head;

            cout << "Queue: [ ";
            while (node != NULL) {
                if (node->next == NULL) {
                    cout << node->data;
                } else {
                    cout << node->data << ", ";
                }
                node = node->next;
            }
            cout << " ]" << endl;
        }
    }

    bool isEmpty() {
        if (head == NULL) {
            return true;
        }
        return false;
    }

    void enQueue(int val) {
        Node *node = new Node(val);
        if (this->isEmpty()) {
            head = node;
            tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }

    int deQueue() {
        if (isEmpty()) {
            return 0;
        }

        Node *node = head;
        int data = node->data;
        head = node->next;
        if (head == NULL) {
            tail = NULL;
        }
        delete node;
        return data;
    }

    void detroyQueue() {
        if (!isEmpty()) {
            Node *node = head;
            while (node != NULL) {
                head = node->next;
                delete node;
                node = head;
            }
            tail = NULL;
        }
    }

    int front() {
        if (isEmpty()) {
            return -1;
        }
        return head->data;
    }
};

int main() {
    Queue *q = new Queue();
    q->enQueue(1);
    q->enQueue(2);
    q->enQueue(3);
    // q->deQueue();
    // q->detroyQueue();
    q->print();

    int first = q->front();
    if (first < 0) {
        cout << "Queue is emoty: ";
    } else {
        cout << "Get first element in queue: " << first;
    }

    return 0;
}