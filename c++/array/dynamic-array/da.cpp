
#include "da.hpp"
#include <iostream>

using namespace std;

template <typename T>
DynamicArray<T>::DynamicArray() {
    this->size = 0;
    this->capacity = 1;
    this->array = new T[capacity];
}

template <typename T>
DynamicArray<T>::~DynamicArray() {
}

template <typename T>
void DynamicArray<T>::add(T value) {
    if (size == capacity) {
        growSize();
    }
    array[size] = value;
    size++;
}

template <typename T>
void DynamicArray<T>::growSize() {
    capacity = capacity * 2;
    T *temp = new T[capacity];

    for (int i = 0; i < size; i++) {
        temp[i] = array[i];
    }
    delete[] array;
    array = temp;
}

template <typename T>
int DynamicArray<T>::getSize() {
    return size;
}

template <typename T>
void DynamicArray<T>::print() {
    for (int i = 0; i < size; i++) {
        cout << array[i] << "\n";
    }
}
