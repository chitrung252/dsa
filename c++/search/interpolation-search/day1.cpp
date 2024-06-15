// CT middle = low +((data - array[low]) *(high - low)) / (array[high] - array[low])

#include "../../array/dynamic-array/da.cpp"
#include <iostream>

using namespace std;

class InterpolationSearch {
public:
    int low;
    int high;
    int middle;
    int *intArray;

    InterpolationSearch(int _low, int _high, int *_array) {
        this->low = _low;
        this->high = _high;
        this->middle = -1;
        this->intArray = _array;
    }

    int find(int data) {
        while (low <= high) {
            cout << "Middle before: " << middle << endl;
            // middle = low + (((double)(high - low) / (intArray[high] - intArray[low])) * (data - intArray[low]));

            middle = low + ((data - intArray[low]) * (double)(high - low)) / (intArray[high] - intArray[low]);

            if (intArray[middle] == data) {
                return middle;
            } else if (intArray[middle] < data) {
                low = middle + 1;
            } else {
                high = middle - 1;
            }
        }
        return -1;
    }
};

int main() {
    DynamicArray<int> *da = new DynamicArray<int>();
    da->add(1);
    da->add(2);
    da->add(3);
    da->add(4);
    da->add(5);
    da->add(6);
    da->add(7);

    InterpolationSearch *is = new InterpolationSearch(0, da->getSize() - 1, da->array);

    int index = is->find(4);

    if (index == -1) {
        cout << "Number is not found" << endl;
    } else {
        cout << "Number found is: " << index + 1 << endl;
    }

    return 0;
}