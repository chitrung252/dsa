#include <iostream>

using namespace std;

class SelectionSort {

public:
    SelectionSort() {
    }

    int *sort(int *ptrArr, size_t size) {
        for (int i = 0; i < size - 1; i++) {
            int indexMin = i;
            for (int j = i + 1; j < size; j++) {
                if (ptrArr[indexMin] > ptrArr[j]) {
                    indexMin = j;
                }
            }
            if (indexMin != i) {
                int term = ptrArr[indexMin];
                ptrArr[indexMin] = ptrArr[i];
                ptrArr[i] = term;
            }
        }
        return ptrArr;
    }
};

int main() {
    const int SIZE = 5;
    int array[] = {5, 2, 3, 4, 1};
    int *ptr = array;
    SelectionSort ss;

    int *newArray = ss.sort(array, SIZE);

    for (int i = 0; i < SIZE; i++) {
        cout << newArray[i] << endl;
    }

    return 0;
}