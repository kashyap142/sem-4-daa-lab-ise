// quick sort
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a , int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(int arr[] , int size)
{
    int i = 0;
    for(i=0; i<size; i++)
        printf("%d " , arr[i]);

    printf("\n");
}

int partition(int arr[] ,int low , int high)
{
    int left = low;
    int right = high;
    int pivot = low;

    while(left < right) {
        while(arr[left] <= arr[low] && left <= high) {
            left++;
        }
        while(arr[right] > arr[low] && right >= low) {
            right--;
        }
        if(left < right)
            swap(& arr[left] , & arr[right]);
    }
    swap(& arr[low] , & arr[right]);
    return right;
}

void quickSort(int arr[] , int low , int high)
{
    int pivot;
    if(low < high) {
        pivot = partition(arr , low , high);
        quickSort(arr , low , pivot - 1);
        quickSort(arr , pivot + 1 , high);
    }
}

int main()
{
    int size;

    printf("Enter size of array: ");
    scanf("%d",&size);

    int arr[size];
    int i = 0;

    // input
    for(i=0; i<size; i++) {
        arr[i] = rand() % 1000;
    }

    printf("Input Array is\n");
    printArray(arr , size);

    clock_t begin = clock();

    quickSort(arr , 0 , size - 1);

    clock_t end = clock();

    double time = (double)(end - begin) / CLOCKS_PER_SEC;

    printf("Time taken for sorting is %.9lf sec\n",time);

    printf("Sorted Array is\n");
    printArray(arr , size);
}

// Kunal
// 15-06 6:28 PM