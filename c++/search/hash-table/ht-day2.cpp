#include <iostream>

using namespace std;

class Item {
public:
    int key;
    int data;

    Item(){};

    Item(int _key, int _data) {
        this->key = _key;
        this->data = _data;
    };
};

class HashTable {
public:
    Item **arr;
    int size;
    int capacity;

    HashTable() {
        this->size = 0;
        this->capacity = 1;
        this->arr =
            (Item **)calloc(this->capacity, sizeof(Item *));

        for (int i = 0; i < this->capacity; i++) {
            arr[i] = NULL;
        }
    };

    void add(int key, int data) {
        Item *item = new Item(key, data);
        arr[size] = item; // why calloc dont need grow size ?
        size++;
    }

    void print() {
        for (int i = 0; i < size; i++) {
            cout << arr[i]->data << endl;
        }
    }

    void growSize() {
        capacity *= 2;
        Item **temp = (Item **)calloc(this->capacity, sizeof(Item *));
        for (int i = 0; i < size; i++) {
            temp[i] = arr[i];
        }
        delete[] arr;
        arr = temp;
    }

    int find(int key) {
        Item *item = arr[key];
        if (item != NULL) {
            return item->data;
        }
        return -1;
    }
};

int main() {
    HashTable *ht = new HashTable();
    ht->add(0, 1);
    ht->add(1, 2);
    ht->add(2, 3);
    ht->add(3, 4);

    ht->print();

    int found = ht->find(3);
    cout << "Found: " << found << "\n";

    return 0;
}