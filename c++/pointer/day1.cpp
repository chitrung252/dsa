// https://www.geeksforgeeks.org/difference-between-stack-allocated-and-heap-allocated-arrays/

#include <iostream>

using namespace std;

const int MAX = 5;

void cumulativeFirstElement(int *firstElement) {
    *firstElement -= 1;
};

void cumulativeFirstElementPointer(int firstElement) {
    firstElement += 10;
};

int main() {
    // store stack;
    int array[MAX];
    int *firstElement;

    array[0] = 2;
    array[1] = 4;
    array[2] = 3;
    array[3] = 5;
    array[4] = 6;

    firstElement = &array[0];

    cumulativeFirstElement(firstElement);

    for (int i = 0; i < MAX; i++) {
        cout << array[i] << endl;
    }
    cout << "================" << endl;

    // store heap;

    int *array2 = new int[MAX];

    array2[0] = 12;
    array2[1] = 14;
    array2[2] = 13;
    array2[3] = 15;
    array2[4] = 16;

    cumulativeFirstElementPointer(array2[0]);

    for (int i = 0; i < MAX; i++) {
        cout << array2[i] << endl;
    }
    return 0;
}
