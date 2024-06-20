#include <iostream>

using namespace std;

const int SIZE = 10;
int array2[SIZE];

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
        high:sortArray(1,1)              - RS Low Mid after sort low: 0
        return
    low:sortArray(0,2)
    mid = 1
        high:sortArray(2,2)              - RS Low Mid after sort low: 1
        return
    =>low:sortArray(0,5)
    mid = 2
        high:sortArray(3,5)              - RS Low Mid after sort low: 2
            mid = 4                         - RS High Mid before sort: 4
            low:sort(3, 4)                  - RS Low Mid before sort:3
            mid = 3
            low:sort(3, 3)
            return
            low:sort(3, 4)                  - RS Low Mid after sort low: 3
        high:sortArray(3,5)              - RS High Mid after sort low: 4

    =>sortArray(0, 10)                   - Main Mid after sort low: 5
    mid = 5
    high:sort(6, 10)
        mid = 8                              - RS High Mid before sort: 8
        low:sortArray(6, 8)
        mid = 7                              - RS Low Mid before sort: 7
        low:sortArray(6, 7)
        mid = 6                              - RS Low Mid before sort: 6
        low:sortArray(6, 6)
        return
        =>low:sortArray(6, 6)                - RS Low Mid after sort: 6
        =>low:sortArray(6, 7)                - RS Low Mid after sort: 7
    =>high:sort(6, 10)                       - RS High Mid after sort low: 8
    high:sort(9, 10)
    mid = 9                                  - RS High Mid before sort: 9
        sortArray(9, 9)
        return
    => high:sort(9, 10)                      - RS High Mid after sort low: 9
       return
    return */
    int *sortArray(int *pt, int low, int high, string fn) {
        if (low < high) {
            int mid = (low + high) / 2;
            // cout << fn << " Mid before sort: " << mid << endl;
            // 5 2 1 0
            sortArray(pt, low, mid, "RS Low");

            // cout << fn << " Mid after sort low: " << mid << endl;
            sortArray(pt, mid + 1, high, "RS High");

            cout << "Merge when low: " << low << " mid: " << mid << " high: " << high << endl;

            mergingArray(pt, low, mid, high);
            return pt;
        }
        return NULL;
    }

    void mergingArray(int *pt, int low, int mid, int high) {
        int l1, l2, i;

        for (l1 = low, l2 = mid + 1, i = low; l1 <= mid && l2 <= high; i++) {
            if (pt[l1] <= pt[l2]) {
                array2[i] = pt[l1++];
            }

            else
                array2[i] = pt[l2++];
        }

        while (l1 <= mid)
            array2[i++] = pt[l1++];

        while (l2 <= high)
            array2[i++] = pt[l2++];

        for (i = low; i <= high; i++)
            pt[i] = array2[i];
    }
};

int main() {
    int array[SIZE] = {40, 2, 4, 10, 14, 20, 31, 9, 8, 12};
    int *pt = array;

    MergeSort ms;

    int *newArray = ms.sortArray(pt, 0, SIZE, "Main");

    for (int i = 0; i < SIZE; i++) {
        cout << newArray[i] << endl;
    }

    return 0;
}