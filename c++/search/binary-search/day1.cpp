
// O logn
//
/* Lý do dùng left + (right - left) / 2 thay vì (left + right) / 2
Trong một số ngôn ngữ lập trình, để tránh lỗi tràn số (overflow) khi left và right đều là các giá trị rất lớn, chúng ta có thể dùng công thức biến đổi:

mid = left + ( right − left) /2 thay vì (left + right) / 2

Điều này đảm bảo rằng chúng ta không bao giờ cộng hai số lớn dẫn đến giá trị vượt quá giới hạn của kiểu dữ liệu số nguyên.
 */
#include "../../array/dynamic-array/da.cpp"

class BinarySearch {
public:
    int lowerBound;
    int upperBound;
    int midPoint;
    int comparisons;
    int index;
    int *intArray;

    BinarySearch(int _lowerBound, int _upperBound, int *_array) {
        this->lowerBound = _lowerBound;
        this->upperBound = _upperBound;
        this->midPoint = -1;
        this->comparisons = 0;
        this->index = -1;
        this->intArray = _array;
    }

    ~BinarySearch();

    int find(int data) {

        while (lowerBound <= upperBound) {
            midPoint = lowerBound + (upperBound - lowerBound) / 2;

            if (intArray[midPoint] == data) {
                return midPoint;
            } else if (intArray[midPoint] < data) {
                lowerBound = midPoint + 1;
            } else {
                upperBound = midPoint - 1;
            }
        }
        return -1;
    };
};

int main() {
    DynamicArray<int> *da = new DynamicArray<int>();
    da->add(1);
    da->add(2);
    da->add(3);
    da->add(4);
    da->add(5);
    da->add(6);
    da->add(55);
    da->add(7);
    da->print();

    int size = da->getSize();

    BinarySearch *bs = new BinarySearch(0, size - 1, da->array);
    int location = bs->find(2);

    if (location != -1)
        printf("\nTim thay phan tu tai vi tri: %d", (location + 1));
    else
        printf("\nKhong tim thay phan tu.");

    return 0;
}
