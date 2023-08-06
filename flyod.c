// flyod algorithm 
#include <stdio.h>
#include <stdlib.h>

void printMatrix(int n , int arr[][n])
{
    int i,j;
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
}

int min(int a , int b)
{
    return (a < b)? a : b;
}

void flyod(int n , int arr[][n])
{
    int i , j, k;
    for(k=0; k<n; k++) {
        for(i=0; i<n; i++) {
            for(j=0; j<n; j++) {
                arr[i][j] = min(arr[i][j] , arr[i][k] + arr[k][j]);
            }
        }
    }
}

int main()
{
    int n,i,j;
    printf("Enter no of vertices: ");
    scanf("%d", &n);

    int arr[20][20];
    printf("Enter weight matrix of graph\n");
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            scanf("%d" ,&arr[i][j]);
        }
    }

    printf("\nInput Weight matrix is\n");
    printMatrix(n , arr);

    flyod(n , arr);

    printf("\nThe distance matrix is\n");
    printMatrix(n , arr);

    return 0;
}
