#include <iostream>

using namespace std;

class InsertionSort {
public:
    InsertionSort() {
    }

    ~InsertionSort() {}

    int *sort(int *ptArray, size_t size) {
        // for (int i = 1; i < size; i++) {
        //     int holePosition = i;
        //     while (ptArray[holePosition - 1] > ptArray[holePosition]) {
        //         int term = ptArray[holePosition];
        //         ptArray[holePosition] = ptArray[holePosition - 1];
        //         ptArray[holePosition - 1] = term;
        //         holePosition--;
        //     }
        // }
        // return ptArray;

        for (int i = 1; i < size; i++) {
            int holePosition = i;
            int valueInsertion = ptArray[i];
            while (ptArray[holePosition - 1] > valueInsertion) {
                ptArray[holePosition] = ptArray[holePosition - 1];
                holePosition--;
            }
            ptArray[holePosition] = valueInsertion;
        }
        return ptArray;
    }
};

int main() {
    const int SIZE = 7;
    int array[] = {5, 4, 2, 1, 3, 0, 6};
    InsertionSort is;

    int *newArray = is.sort(array, SIZE);
    for (int i = 0; i < SIZE; i++) {
        cout << newArray[i] << endl;
    }

    return 0;
}