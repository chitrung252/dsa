#include <iostream>

using namespace std;

class MergeSort {
public:
    MergeSort() {
    }
    ~MergeSort() {}

    /* sortArray(0,10)
    mid = 5                            MainMid before sort: 5
    low:sortArray(0, 5)                  - RS Low Mid before sort: 2
    mid = 2
    low:sortArray(0,2)                   - RS Low Mid before sort: 1
    mid = 1
    low:sortArray(0,1)                   - RS Low Mid before sort: 0
    mid = 0
        high:sortArray(1,10)             - RS Low Mid before after sort low: 0
        mid = 5
            low:sortArray(0, 5)
            mid= 2
            low:sortArray(0,2)
            mid = 1
            low:sortArray(0,1)
            mid = 0
        high:sortArray(6, 10)
        mid = 8
            low:sortArray(0, 8)
            mid = 4
            low:sortArray(0, 4)
            mid= 2
            low:sortArray(0,2)
            mid = 1
            low:sortArray(0,1)
            mid = 0
        high:sortArray(9, 10)
        mid = 9
            low:sortArray(0, 9)
            mid = 4
            low:sortArray(0, 4)
            mid= 2
            low:sortArray(0,2)
            mid = 1
            low:sortArray(0,1)
            mid = 0
        high:sortArray(10, 10)

        return
    return */
    int *sortArray(int *pt, int low, int high, string fn) {
        if (low < high) {
            int mid = (low + high) / 2;
            cout << fn << " Mid before sort: " << mid << endl;
            // 5 2 1 0
            sortArray(pt, low, mid, "RS Low");

            cout << fn << " Mid before after sort low: " << mid << endl;
            sortArray(pt, mid + 1, high, "RS High");
            return pt;
        }
        return NULL;
    }

    void merge() {
    }
};

int main() {
    const int SIZE = 10;
    int array[SIZE] = {40, 2, 4, 10, 14, 20, 31, 9, 8, 12};

    int *pt = array;

    MergeSort ms;

    int *newArray = ms.sortArray(pt, 0, SIZE, "Main");

    for (int i = 0; i < SIZE; i++) {
        // cout << newArray[i] << endl;
    }

    return 0;
}