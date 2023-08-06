// merge sort
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printArray(int arr[] , int size)
{
    int i;
    for(i=0; i<size ; i++)
        printf("%d " , arr[i]);
    
    printf("\n");
}

void merge(int arr[] , int low , int mid , int high)
{
    int size = high + 1 - low;
    int temp[size];
    int left = low; 
    int right = mid + 1;
    int k = 0;
    while(left <= mid && right <= high) {
        if(arr[left] <= arr[right]) {
            temp[k] = arr[left];
            left++;
        }
        else {
            temp[k] = arr[right];
            right++;
        }
        k++;
    }

    while(left <= mid) {
        temp[k] = arr[left];
        left++;
        k++;
    }

    while(right <= high) {
        temp[k] = arr[right];
        k++;
        right++;
    }

    for(k=0; k<size; k++)
        arr[k+low] = temp[k];
    
    free(temp); // not mandatory
}

void mergeSort(int arr[] , int low , int high)
{
    if(low >= high)
        return;
    int mid = (low + high) / 2;
    mergeSort(arr , low , mid);
    mergeSort(arr , mid + 1 , high);
    merge(arr , low , mid , high);
}

int main()
{
    int size , i;
    int z;
    printf("Enter size of array: ");
    scanf("%d" , &size);

    int arr[size];

    for(i=0; i<size; i++) {
        arr[i] = rand() % 1000;
    }
    printf("Unsorted array is\n");
    printArray(arr , size);

    clock_t begin = clock();

    mergeSort(arr , 0 , size - 1);

    clock_t end = clock();

    double timeTaken = (double)(end - begin) / CLOCKS_PER_SEC;

    printf("Time taken %.9lf \n" , timeTaken);
    
    printf("Sorted array is\n");
    printArray(arr , size); 
    return 0;
}

// Kunal
// 27-05 1:49 AM