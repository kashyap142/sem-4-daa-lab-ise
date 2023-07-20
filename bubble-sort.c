#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void printArray(int arr[] , int n)
{
    int i;
    for( i = 0; i < n; i++)
        printf("%d ",arr[i]);
    
    printf("\n");
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int arr[] , int n)
{
    int i,j;
    int count = 0; // count number of swaps

    for( i = 0; i < n - 1; i++) {
        for( j = 0; j < n - 1 - i; j++) {    
            if( arr[j] > arr[j+1] ) {
                swap( & arr[j] , & arr[j+1] ); // pass by reference
                count++;
            }
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
    for( i = 0; i < n; i++) 
        scanf("%d",&arr[i]);

    printf("Input array is\n");
    printArray(arr , n);
    
    clock_t begin = clock();

    bubbleSort(arr , n);
    
    clock_t end = clock();

    double time_taken = (double)(end - begin) / CLOCKS_PER_SEC;

    printf("Time taken in sorting is %.9lf\n", time_taken);

    printf("Sorted array is\n");
    printArray(arr , n);

    return 0;
}

// Kunal
// 26-05 11:37 PM