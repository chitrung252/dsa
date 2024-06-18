#include <stdio.h>


void insert_array(){
    int arrayInteger[] = {1, 3, 5, 7, 8};
    int number = 10, k = 3, n = 5;
    int i = 0, j = n;

    printf("Danh sách phần tử trong mảng ban đầu \n");

    for (i = 0; i < n; i++)
    {
        printf("Array[%d] = %d \n", i, arrayInteger[i]);
    }

    n = n + 1;

    while (j >= k) {
        arrayInteger[j + 1] = arrayInteger[j];
        j = j - 1;
    }

    arrayInteger[k] = number;

    printf("Danh sach phan tu cua mang sau hoat dong chen:\n");

    for (i = 0; i < n; i++)
    {
        printf("Array[%d] = %d \n", i, arrayInteger[i]);
    }
}

void delete_array(){
   int LA[] = {1,3,5,7,8};
   int k = 3, n = 5;
   int i, j;
   
   printf("Danh sach phan tu trong mang ban dau:\n");
	
   for(i = 0; i<n; i++) {
      printf("LA[%d] = %d \n", i, LA[i]);
   }
    
   j = k;
	
   while( j < n){
      LA[j-1] = LA[j];
      j = j + 1;
   }
	
   n = n -1;
   
   printf("Danh sach phan tu trong mang sau hoat dong xoa:\n");
	
   for(i = 0; i<n; i++) {
      printf("LA[%d] = %d \n", i, LA[i]);
   }
}

void search_array(){
     int LA[] = {1,3,5,7,8};
   int item = 5, n = 5;
   int i = 0, j = 0;
   
   printf("Danh sach phan tu trong mang ban dau:\n");
	
   for(i = 0; i<n; i++) {
      printf("LA[%d] = %d \n", i, LA[i]);
   }
    
   while( j < n){
	
      if( LA[j] == item ){
         break;
      }
		
      j = j + 1;
   }
	
   printf("Tim thay phan tu %d tai vi tri %d\n", item, j+1);
}

void update_array(){
   int LA[] = {1,3,5,7,8};
   int k = 3, n = 5, item = 10;
   int i, j;
   
   printf("Danh sach phan tu trong mang ban dau:\n");
	
   for(i = 0; i<n; i++) {
      printf("LA[%d] = %d \n", i, LA[i]);
   }
    
   LA[k-1] = item;

   printf("Danh sach phan tu trong mang sau hoat dong update:\n");
	
   for(i = 0; i<n; i++) {
      printf("LA[%d] = %d \n", i, LA[i]);
   }
}

int main()
{
    update_array();
}