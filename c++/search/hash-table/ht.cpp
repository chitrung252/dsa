#include "ht.hpp"
#include <iostream>

using namespace std;

HashItem::HashItem(char _key, char _data) {
    this->key = _key;
    this->data = _data;
}

HashItem HashTable::createItem(char key, char data) {
    HashItem ht = new HashItem(key, data);
    ht.key = (char *)malloc(strlen(key) + 1);
    ht.data = (char *)malloc(strlen(data) + 1);

    strcpy(ht.key, key);
    strcpy(ht.data, data);
    return ht;
}

HashTable::HashTable(int _size) {
    this->size = _size;
    this->count = 0;
    this->items = new HashItem[size];

    for (int i = 0; i < size; i++) {
        this->items[i] = NULL;
    }
}

HashTable::hashFunction(char key) {
    unsigned long i = 0;

    for (int j = 0; key[j]; j++)
        i += key[j];

    return i % size;
}

HashTable::insert(char key, char data) {
    HashItem *ht = createItem(key, data);
    int index = hashFunction(key);

    HashItem *currentItem = items[index];
    if (currentItem == NULL) {
        if (count == size) {
            // HashTable is full.
            printf("Insert Error: Hash Table is full\n");
            return;
        }

        // Insert directly.
        items[index] = ht;
        count++;
    } else {
        if (strcmp(currentItem->key, key) == 0) {
            strcpy(items[index]->data, data);
            return;
        } else {
            // Scenario 2: Handle the collision.
            // handle_collision(table, index, item);
            return;
        }
    }
}

int main() {

    HashTable ht = new HashTable(10);

    for (int i = 0; i < 10; i++) {
        string idxStr = to_string(i);
        string valStr = to_string(i + 10);
        char const *idxChar = idxStr.c_str();
        char const *vlChar = valStr.c_str();

        ht.insert(idxChar, vlChar);
    }

    return 0;
}
