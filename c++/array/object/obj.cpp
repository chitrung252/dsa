#include <iostream>

using namespace std;

class MyClass {

public:
    void method(int i) {

        cout << "object " << i + 1 << endl;
    }
};

int main() {

    MyClass *array_of_objects = new MyClass[5]; // Creating an array of MyClass objects using 'new'

    for (int i = 0; i < 5; i++) {

        array_of_objects[i].method(i);
    }
}