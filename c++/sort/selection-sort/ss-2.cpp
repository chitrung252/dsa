#include <iostream>

using namespace std;

class SelectionSort {
public:
    SelectionSort() {
    }

    ~SelectionSort() {
    }

    int *sort(int *pt, size_t size) {
        for (int i = 0; i < size - 1; i++) {

            int minIndex = i;
            for (int j = i + 1; j < size; j++) {
                if (pt[minIndex] > pt[j])
                    minIndex = j;
            }
            if (minIndex != i) {
                int term = pt[minIndex];
                pt[minIndex] = pt[i];
                pt[i] = term;
            }
        }
        return pt;
    }
};

int main() {
    const int SIZE = 5;
    int array[] = {30, 24, 1, 5, 400};

    SelectionSort ss;

    int *pt = array;

    int *newArray = ss.sort(pt, SIZE);

    for (int i = 0; i < SIZE; i++) {
        cout << newArray[i] << endl;
    }

    return 0;
}