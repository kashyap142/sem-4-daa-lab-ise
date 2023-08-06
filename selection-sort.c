// selection sort
#include <stdio.h>
#include <stdlib.h>

void printArray(int arr[] , int n)
{
    int i;
    for( i=0; i<n; i++)
        printf("%d " , arr[i]);

    printf("\n");
}

void swap(int *a , int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int arr[] , int n)
{
    if(n < 2) {
        printf("Number of swaps are 0\n");
        return;
    }
    int i,j;
    int count = 0; // count number of swaps
    int min_index = 0;
    for( i = 0; i < n - 1; i++ ) {
        min_index = i;
        for( j = i + 1; j < n; j++ ) {
            if( arr[min_index] > arr[j] ) {
                min_index = j;
            }
        }
        if(min_index != i) {
            swap( & arr[min_index] , & arr[i]); // pass by reference
            count++;
        }
    }
    printf("Number of swaps are %d\n" , count);
}

int main()
{
    int n , i;
    printf("Enter size of array: ");
    scanf("%d",&n);

    int arr[n];
    printf("Enter elements of array\n");
    for( i = 0; i < n; i++) {
        // scanf("%d",&arr[i]);
        arr[i] = rand() % 1000;
    }

    printf("Input array is\n");
    printArray(arr , n);

    selectionSort(arr , n);

    printf("Sorted array is\n");
    printArray(arr , n);

    return 0;
}

// Kunal
// 26-05 11:59 PM