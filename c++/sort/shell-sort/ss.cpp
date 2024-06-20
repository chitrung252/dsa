

#include <iostream>
#include <stdio.h>

using namespace std;

/* Function to print the array */
void printArray(int a[], int n) {
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

// void shellSort(int a[], int n) {

//     int interval = 1;

//     while (interval < n / 3) {
//         interval = interval * 3 + 1;
//     }
//     while (interval > 0) {

//         /* n = 9 ,  outer = 4
//                 interval = 4
//                 valueInsert = 0
//                 inner = outer = 4
//                      while:step 1: 4 > 3 && 31 > 0 : true => a[4] = 31; inner = 0;
//                      while:step 2: 0 > 3 && a[0] = 31 >= 0 : false
//                 a[0] = 0
//            outer = 5
//                 interval = 4
//                 valueInsert = 4
//                 inner = outer = 5
//                      while: step1 : 5 > 3 && 12 >= 4: true => a[5] = 12: inner = 1
//                      while:step 2: 1 > 3 && a[1] = 12 >= 4  : false
//                 a[1] = 4
//             ....

//             0 4 5 1 2 12 10 3 31

//             interval = (interval - 1) / 3 = 1;

//             n = 9, outer = 1, interval = 1
//             inner = outer = 1, valueInsert = 4
//                 while: step 1: 1 > 0 && a[0] = 0 >= 4: false
//             a[1] = 4

//             interval = 1
//             inner = outer = 2, valueInsert = 5
//                 while: step1: 2 > 0 && a[1] = 4 >= 5 : false
//             a[2] = valueInsert

//             interval = 1
//             inner = outer = 3, valueInsert = 1
//                 while: step1: 3 > 0 && a[2] = 5 >= 1: true
//                             a[3] = a[2] = 5
//                             inner = 2
//                             =>  0 4 5 5 2 12 10 3 31
//                        step2: 2 > 0 && a[1] = 4 >= 1: true
//                             a[2] = a[1] = 4
//                             =>  0 4 4 5 2 12 10 3 31
//                             inner = 1
//                        step3: 1 > 0 && a[0] = 0 >= 1: false
//                 a[1] = 1 =>  0 1 4 5 2 12 10 3 31

//         */
//         for (int outer = interval; outer < n; outer++) {
//             int valueInsert = a[outer];
//             int inner = outer;

//             while (inner > interval - 1 && a[inner - interval] >= valueInsert) {

//                 a[inner] = a[inner - interval];
//                 inner = inner - interval;

//                 cout << "inner " << inner << endl;
//                 /* code */
//             }
//             a[inner] = valueInsert;
//         }
//         cout << "interval: " << interval << endl;
//         printArray(a, n);
//         // 31 12 5 1 0  4 10  3  2
//         //  0  4 5 1 2 12 10  3 31 => while
//         //  0  4 5 1 2 12 10  3 31 => if
//         //  0  1 2 3 4  5 10 12 31 => while
//         //  0  4 1 2 5 10  3 12 31 => if
//         interval = (interval - 1) / 3;
//     }
// }

// h = h * 3 + 1

void shellSort(int a[], int n) {
    int interval = 1;

    while (interval < n / 3) {
        interval = interval * 3 + 1;
    }

    while (interval > 0) {
        for (int outer = interval; outer < n; outer++) {
            int valueInsert = a[outer];
            int inner = outer;
            while (inner > interval - 1 && a[inner - interval] >= valueInsert) {
                a[inner] = a[inner - interval];
                inner = inner - interval;
            }
            a[inner] = valueInsert;
        }
        interval = (interval - 1) / 3;
    }
}

int main() {
    int a[] = {31, 12, 5, 1, 0, 4, 10, 3, 2};
    int n = sizeof(a) / sizeof(a[0]);
    // printf("Before sorting array elements are - \n");
    // printArray(a, n);
    shellSort(a, n);
    printf("After sorting array elements are - \n");
    printArray(a, n);
}