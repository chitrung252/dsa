#include <iostream>
#include <stdio.h>

using namespace std;
/* Function to merge the subarrays of a[] */
// void merge(int a[], int beg, int mid, int end) {
//     cout << "begin: " << beg << " mid: " << mid << " end: " << end << endl;
//     int i, j, k;
//     int n1 = mid - beg + 1;
//     cout << "n1: " << n1 << endl;
//     int n2 = end - mid;
//     cout << "n2: " << n1 << endl;
//     int LeftArray[n1], RightArray[n2]; // temporary arrays

//     /* copy data to temp arrays */
//     for (int i = 0; i < n1; i++) {
//         LeftArray[i] = a[beg + i];
//     }

//     for (int j = 0; j < n2; j++) {
//         RightArray[j] = a[mid + 1 + j];
//     }

//     i = 0;   /* initial index of first sub-array */
//     j = 0;   /* initial index of second sub-array */
//     k = beg; /* initial index of merged sub-array */

//     while (i < n1 && j < n2) {
//         if (LeftArray[i] <= RightArray[j]) {
//             a[k] = LeftArray[i];
//             i++;
//         } else {
//             a[k] = RightArray[j];
//             j++;
//         }
//         k++;
//     }

//     while (i < n1) {
//         a[k] = LeftArray[i];
//         i++;
//         k++;
//     }

//     while (j < n2) {
//         a[k] = RightArray[j];
//         j++;
//         k++;
//     }
// }

// void merge(int a[], int beg, int mid, int end) {
//     int i, j, k;

//     int n1 = mid - beg + 1;
//     int n2 = end - mid;

//     int LeftArray[n1], RightArray[n2];

//     for (int i = 0; i < n1; i++) {
//         LeftArray[i] = a[beg + i];
//         cout << "LeftArray[i]: " << LeftArray[i] << ", ";
//     }
//     cout << "\n";
//     for (int j = 0; j < n2; j++) {
//         RightArray[j] = a[mid + 1 + j];
//         cout << "RightArray[j]: " << RightArray[j] << ", ";
//     }
//     cout << "\n";

//     i = 0;
//     j = 0;
//     k = beg;

//     while (i < n1 && j < n2) {
//         if (LeftArray[i] <= RightArray[j]) {
//             a[k] = LeftArray[i];
//             i++;
//         } else {
//             a[k] = RightArray[j];
//             j++;
//         }
//         k++;
//     }

//     while (i < n1) {
//         a[k] = LeftArray[i];
//         i++;
//         k++;
//     }

//     while (j < n2) {
//         a[k] = RightArray[j];
//         j++;
//         k++;
//     }
// }

void merge(int a[], int begin, int middle, int end) {
    int i, j, k;

    int n1 = middle - begin + 1;
    int n2 = end - middle;

    int leftArray[n1], rightArray[n2];

    for (int i = 0; i < n1; i++) {
        leftArray[i] = a[begin + i];
    }

    for (int j = 0; j < n2; j++) {
        rightArray[j] = a[middle + 1 + j];
    }

    i = 0;
    j = 0;
    k = begin;

    while (i < n1 && j < n2) {
        if (leftArray[i] <= rightArray[j]) {
            a[k] = leftArray[i];
            i++;
        } else {
            a[k] = rightArray[j];
            j++;
        }

        k++;
    }

    while (i < n1) {
        a[k] = leftArray[i];
        i++;
        k++;
    }

    while (i < n2) {
        a[k] = rightArray[j];
        j++;
        k++;
    }
}

void mergeSort(int a[], int beg, int end) {
    if (beg < end) {
        int mid = (beg + end) / 2;
        mergeSort(a, beg, mid);
        mergeSort(a, mid + 1, end);
        merge(a, beg, mid, end);
    }
}

/* Function to print the array */
void printArray(int a[], int n) {
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int main() {
    int a[] = {31, 12, 5, 1, 0, 4, 10, 3, 2};
    int n = sizeof(a) / sizeof(a[0]);
    // printf("Before sorting array elements are - \n");
    // printArray(a, n);
    mergeSort(a, 0, n - 1);
    printf("After sorting array elements are - \n");
    printArray(a, n);
    return 0;
}
