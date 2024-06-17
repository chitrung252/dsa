

template <typename T>
class DynamicArray {
public:
    T *array;

    int size;

    int capacity;

    DynamicArray();
    ~DynamicArray();

    void add(T value);
    void growSize();
    void print();
    int getSize();
};
