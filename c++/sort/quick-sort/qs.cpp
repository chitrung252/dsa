// C++ Implementation of the Quick Sort Algorithm.
#include <iostream>
using namespace std;

// int partition(int arr[], int start, int end) {

//     int pivot = arr[start];
//     cout << "pivot: " << pivot << endl;
//     int count = 0;
//     for (int i = start + 1; i <= end; i++) {
//         if (arr[i] <= pivot)
//             count++;
//     }
//     cout << "count: " << count << endl;
//     // Giving pivot element its correct position
//     int pivotIndex = start + count;
//     cout << "pivotIndex: " << pivotIndex << endl;
//     cout << "Prepare swap value: " << arr[pivotIndex] << " and " << arr[start] << endl;
//     swap(arr[pivotIndex], arr[start]);

//     // Sorting left and right parts of the pivot element
//     int i = start, j = end;

//     while (i < pivotIndex && j > pivotIndex) {

//         while (arr[i] <= pivot) {
//             i++;
//         }

//         while (arr[j] > pivot) {
//             j--;
//         }

//         if (i < pivotIndex && j > pivotIndex) {
//             cout << "HERE" << endl;
//             swap(arr[i++], arr[j--]);
//         }
//     }

//     return pivotIndex;
// }

// int partition(int arr[], int start, int end) {
//     int pivot = arr[start];

//     int count = 0;

//     for (int i = start + 1; i <= end; i++) {
//         if (arr[i] <= pivot)
//             count++;
//     }

//     int pivotIndex = start + count;
//     swap(arr[pivotIndex], arr[start]);

//     int i = start, j = end;

//     while (i < pivotIndex && j > pivotIndex) {
//         while (arr[i] <= pivot) {
//             i++;
//         }
//         while (arr[j] > pivot) {
//             j++;
//         }
//         if (i < pivotIndex && j > pivotIndex) {
//             swap(arr[i--], arr[j--]);
//         }
//     }
//     cout << "pivotIndex: " << pivotIndex << endl;
//     return pivotIndex;
// }

// int partition(int arr[], int begin, int end) {
//     cout << "begin: " << begin << endl;
//     cout << "end: " << end << endl;
//     int pivot = arr[begin];

//     int count = 0;
//     for (int i = begin + 1; i <= end; i++) {
//         if (arr[i] <= pivot) {
//             count++;
//         }
//     }

//     int pivotIndex = count + begin;

//     swap(arr[pivotIndex], arr[begin]);

//     int i = begin, j = end;
//     while (i < pivotIndex && j > pivotIndex) {
//         while (arr[i] <= pivot) {
//             i++;
//         }

//         while (arr[j] > pivot) {
//             j++;
//         }
//         if (i < pivotIndex && j > pivotIndex) {
//             swap(arr[i--], arr[j--]);
//         }
//     }

//     return pivotIndex;
// }

int partition(int arr[], int begin, int end) {
    int pivot = arr[begin];

    int count = 0;

    for (int i = begin + 1; i <= end; i++) {
        if (arr[i] < pivot) {
            count++;
        }
    }

    int indexPivot = begin + count;
    swap(arr[indexPivot], arr[begin]);

    int i = begin, j = end;
    while (i < indexPivot && j > indexPivot) {
        while (arr[i] < indexPivot) {
            i++;
        }
        while (arr[j] > indexPivot) {
            j++;
        }
        if (i < indexPivot && j > indexPivot) {
            swap(arr[i--], arr[j--]);
        }
    }
    return indexPivot;
}

void quickSort(int arr[], int start, int end) {

    // base case
    if (start >= end)
        return;

    // partitioning the array
    int p = partition(arr, start, end);

    // Sorting the left part
    quickSort(arr, start, p - 1);

    // Sorting the right part
    quickSort(arr, p + 1, end);
}

int main() {

    int arr[] = {9, 3, 4, 2, 1, 8};
    int n = 6;

    quickSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
