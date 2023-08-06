// binary search
#include <stdio.h>

int binarySearch(int arr[] , int n , int key)
{
    int low = 0;
    int high = n - 1;
    int mid;
    int count = 0; // count number of comparisons
    while(low <= high) {
        count++;
        mid = (low + high) / 2;
        if(arr[mid] == key) {
            printf("Number of comparisons %d \n" , count);
            return mid;
        }
        else if(arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1; 
    }
    printf("Number of comparisons %d \n" , count);
    return -1;
}

int main()
{
    int n , i , key;
    printf("Enter size of array: " );
    scanf("%d" , &n);

    int arr[n];
    printf("Enter elements of array in sorted order\n");
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    
    printf("Enter element to search ");
    scanf("%d",&key);

    int index = binarySearch(arr , n , key);

    if(index == -1) 
        printf("%d not found\n" , key);
    else 
        printf("%d found at %d index\n" , key , index);

    return 0;
}

// Kunal
// 27-05 01:20 AM