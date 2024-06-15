

class HashItem {

public:
    char data;

    char key;

    HashItem(char _data, char _key);

    ~HashItem();
};

class HashTable {
private:
    HashItem *items;
    int size;
    int count;

public:
    HashTable();

    ~HashTable();

    HashItem createItem(int key, int data);

    HashItem *search(int data);

    void insert(int key, int data);

    HashItem remove(HashItem item);

    unsigned long hashFunction(char *key);
}
