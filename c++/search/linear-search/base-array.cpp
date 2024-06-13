#include <iostream>

using namespace std;

const int MAX = 20;

int intArray[MAX] = {1, 2, 3, 4, 6, 7, 9, 11, 12, 14, 15, 16, 17, 19, 33, 34, 43, 45, 55, 66};

void display() {
    int i;
    printf("[");

    // duyet qua tat ca phan tu
    for (i = 0; i < MAX; i++) {
        printf("%d ", intArray[i]);
    }

    printf("]\n");
}

int find(int data) {
    int comparisons = 0;
    int index = -1;
    int i;

    for (int i = 0; i < MAX; i++) {
        comparisons++;
        if (data == intArray[i]) {
            index = i;
            break;
        }
    }
    printf("Tong so phep so sanh da thuc hien: %d", comparisons);
    return index;
}

int main() {

    printf("Mang du lieu dau vao: ");
    display();
    int location = find(66);

    // neu tim thay phan tu
    if (location != -1)
        printf("\nTim thay phan tu tai vi tri: %d", (location + 1));
    else
        printf("Khong tim thay phan tu.");
    return 0;
}
