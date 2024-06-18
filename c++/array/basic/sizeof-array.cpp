#include <iostream>

using namespace std;

template <size_t N>
int lengthArray(int (&arr)[N]) {
    cout << "\nAddress array in function: " << &arr << endl;
    return sizeof(arr) / sizeof(int);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 8};
    cout << "Address array[0] in main: " << arr << endl;
    cout << "Address array in main: " << &arr << endl;
    cout << "Length main: " << sizeof(arr) / sizeof(int) << endl;

    int lengthFn = lengthArray(arr);
    cout << "Length function: " << lengthFn << endl;
}

int lengthArray(int (*arr)[9]) {
    cout << "Address array[0] in function: " << &arr[0] << endl;
    cout << "Address array[1] in main: " << &arr[1] << endl;
    cout << "Address array in function: " << &arr << endl;
    return sizeof(*arr) / sizeof(*arr[0]);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 8};
    cout << "Address array[0] in main: " << arr << endl;
    cout << "Address array[1] in main: " << &arr[1] << endl;
    cout << "Address array in main: " << &arr << endl;
    cout << "Length main: " << sizeof(arr) / sizeof(int) << endl;

    int lengthFn = lengthArray(&arr);

    cout << "Length function: " << lengthFn << endl;
}
