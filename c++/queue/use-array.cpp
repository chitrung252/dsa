#include <iostream>

using namespace std;

struct Queue {
    int front, rear, capacity;
    int *queue;
    Queue(int c) {
        front = rear = 0;
        capacity = c;
        queue = new int[c];
    }
    ~Queue() {
        cout << "\nRemove queue in memory\n";
        delete[] queue;
    }
    void queueEnqueue(int data) {
        if (capacity == rear) {
            cout << "\nQueue is full" << endl;
            return;
        } else {
            queue[rear] = data;
            rear++;
        }
    };

    void queueDequeue() {
        if (front == rear) {
            cout << "\nQueue is empty" << endl;
            return;
        } else {
            for (int i = 0; i < rear - 1; i++) {
                queue[i] = queue[i + 1];
            }
            rear--;
        }
    };
    void queueDisplay() {
        int i;
        if (front == rear) {
            printf("\nQueue is Empty\n");
            return;
        }

        // traverse front to rear and print elements
        for (i = front; i < rear; i++) {
            if (i == rear - 1) {
                printf(" %d ", queue[i]);
            } else {
                printf(" %d <-- ", queue[i]);
            }
        }
        return;
    };

    void queueFront() {
        if (front == rear) {
            printf("\nQueue is Empty\n");
            return;
        }
        printf("\nFront Element is: %d", queue[front]);
        return;
    };
};

int main() {
    // Create a queue of capacity 4
    Queue q(4);

    // print Queue elements
    q.queueDisplay();

    // inserting elements in the queue
    q.queueEnqueue(20);
    q.queueEnqueue(30);
    q.queueEnqueue(40);
    q.queueEnqueue(50);

    // print Queue elements
    q.queueDisplay();

    // insert element in the queue
    q.queueEnqueue(60);

    // print Queue elements
    q.queueDisplay();

    q.queueDequeue();
    q.queueDequeue();

    printf("\n\nafter two node deletion\n\n");

    // print Queue elements
    q.queueDisplay();

    // print front of the queue
    q.queueFront();
}
