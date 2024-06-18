#include <iostream>

using namespace std;

class BubbleSortCustom {
public:
    BubbleSortCustom() {}

    ~BubbleSortCustom() {}

    int *sort(int *ptr, size_t size) {

        cout << "Length: " << size << endl;

        for (int i = 0; i < size - 1; i++) {
            for (int j = i + 1; j < size; j++) {
                if (ptr[i] > ptr[j]) {
                    swap(ptr, i, j);
                }
            }
        }

        return ptr;
    }

    void swap(int *ptr, int i, int j) {
        int term = ptr[i];
        ptr[i] = ptr[j];
        ptr[j] = term;
    }
};

int main() {
    int array[5] = {2, 3, 4, 5, 1};
    int size = sizeof(array) / sizeof(int);

    int *ptr = array;
    BubbleSortCustom bs;

    int *newArray = bs.sort(ptr, size);

    for (int i = 0; i < size; i++) {
        cout << newArray[i] << endl;
    }

    return 0;
}