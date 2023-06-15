#include <stdio.h>

int linearSearch(int arr[] , int size , int key)
{
    int i;
    int count = 0; // count number of comparisons
    for(i = 0 ; i < size ; i++ ) {
        count++;
        if(arr[i] == key)
            break;
    }
    printf("Number of comparisons are %d\n", count);
    if(i != size)
        return i;
    return -1;
}

int main()
{
    int n , i , key;
    printf("Enter size of array: " );
    scanf("%d" , &n);

    int arr[n];
    printf("Enter elements of array\n");
    for(i=0; i<n; i++)
        scanf("%d", &arr[i]);
    
    printf("Enter element to search ");
    scanf("%d",&key);

    int index = linearSearch(arr , n , key);
    if(index == -1) 
        printf("%d not found\n" , key);
    else 
        printf("%d found at %d index\n" , key , index);

    return 0;
}

// Kunal
// 27-05 1:07 AM