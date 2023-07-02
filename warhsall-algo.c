#include <stdio.h>
#include <stdlib.h>

void printMatrix(int n , int arr[][n])
{
    int i,j;
    for(i=1; i<n; i++) {
        for(j=1; j<n; j++) {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
}

int max(int a , int b)
{
    return (a > b)? a : b;
}

void warshall(int n , int arr[][n])
{
    int i,j,k;
    for(k=1; k<n; k++) {
        for(i=1; i<n; i++) {
            for(j=1; j<n; j++) {
                if(arr[i][j] == 0)
                    arr[i][j] = max(arr[i][j] , (arr[i][k] && arr[k][j]));
            }
        }
    }
}

int main()
{
    int n ,i, j ,e , begin, end;
    printf("Enter no of vertices: " );
    scanf("%d",&n);
    n++; // for array
    int arr[n][n];
    // initialize the array with 0
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++)
            arr[i][j] = 0;
    }
    printf("Enter number of edges: ");
    scanf("%d",&e);

    for(i=0; i<e; i++) {
        printf("Enter end vertics of the edge: ");
        scanf("%d %d",&begin , &end);
        arr[begin][end] = 1;
    }

    printf("\nAdjacency matrix is\n");
    printMatrix(n , arr);

    warshall(n , arr);

    printf("\nTransitive closure is\n");
    printMatrix(n , arr);

    return 0;
}
