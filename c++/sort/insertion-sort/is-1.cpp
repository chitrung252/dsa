#include <iostream>

using namespace std;

class InsertionSort {
public:
    InsertionSort() {
    }
    ~InsertionSort() {
    }

    int *sort(int *ptr, size_t size) {
        for (int i = 1; i < size; i++) {
            int valueInsertion = ptr[i];
            int holePosition = i;
            while (holePosition > 0 && ptr[holePosition - 1] > valueInsertion) {
                ptr[holePosition] = ptr[holePosition - 1];
                holePosition--;
            }

            ptr[holePosition] = valueInsertion;
        }

        return ptr;
    }
};

int main() {
    InsertionSort is;

    int arr[] = {1, 5, 3, 6, 7, 8};
    int size = sizeof(arr) / sizeof(int);

    int *ptr = arr;

    int *newArray = is.sort(arr, size);

    for (int i = 0; i < size; i++) {
        cout << newArray[i] << endl;
    }

    return 0;
}