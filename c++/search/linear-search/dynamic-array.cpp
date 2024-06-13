#include <iostream>

using namespace std;

template <typename T>
class LinearSearch {
private:
    T *array;
    int size;
    int capacity;

public:
    LinearSearch() {
        this->capacity = 1;
        this->size = 0;
        this->array = new T[capacity];
    };

    ~LinearSearch();

    bool add(T value);
    int getSize();
    int getCapacity();
    void growArray();
    void print();
    int search(T val);
};

template <typename T>
bool LinearSearch<T>::add(T value) {
    if (size == capacity) {
        growArray();
    }
    array[size] = value;
    size++;
    return false;
}

template <typename T>
int LinearSearch<T>::getSize() {
    return size;
}

template <typename T>
int LinearSearch<T>::getCapacity() {
    return capacity;
}

template <typename T>
void LinearSearch<T>::growArray() {
    T *temp = new T[capacity * 2];
    capacity = capacity * 2;

    // copy element of old array in newly created array
    for (int i = 0; i < size; i++) {
        temp[i] = array[i];
    }

    // Delete old array
    delete[] array;

    // Assign newly created temp array to original array
    array = temp;
}

template <typename T>
void LinearSearch<T>::print() {
    cout << "[ ";
    for (int i = 0; i < size; i++) {
        cout << array[i];
        if (i < size - 1) {
            cout << ", ";
        }
    }
    cout << " ]" << endl;
}

template <typename T>
int LinearSearch<T>::search(T value) {
    for (int i = 0; i < size; i++) {
        if (array[i] == value) {
            return i;
        }
    }
    return -1;
}

int main() {

    LinearSearch<char> *ls = new LinearSearch<char>();
    ls->add('a');
    ls->add('b');
    ls->add('c');
    ls->add('d');
    ls->add('e');
    ls->add('f');
    ls->add('g');
    ls->add('h');
    ls->print();

    int index = ls->search('h');
    if (index == -1) {
        cout << "Không tìm thấy phần tử" << endl;
    } else {
        cout << "Index tìm được ở vị trí: " << index << endl;
    }
    return 0;
}
