#include <stdio.h>
#include <stdlib.h>

int max(int a, int b)
{
    return (a > b) ? a : b;
}

void knapsack(int capacity, int n, int weight[], int profit[])
{
    int v[100][200] = {0}, x[10] = {0}, i, j, sum = 0;
    for (i = 1; i <= n; i++) {
        for (j = 0; j <= capacity; j++) {
            if (j >= weight[i]) {
                v[i][j] = max(v[i - 1][j], v[i - 1][j - weight[i]] + profit[i]);
            }
            else {
                v[i][j] = v[i - 1][j];
            }
        }
    }

    i = n;
    j = capacity;
    while (i > 0 && j > 0) {
        if (v[i][j] != v[i - 1][j]) {
            x[i] = 1;
            j = j - weight[i];
        }
        i--;
    }

    printf("The optimal set of items is\n");
    for (i = 1; i <= n; i++) {
        if (x[i] == 1) {
            printf("%d ", i);
            sum += profit[i];
        }
    }

    printf("\nTotal profit = %d\n", sum);
}

int main()
{
    int n, i, capacity;

    printf("Enter number of items: ");
    scanf("%d", &n);

    int weight[n + 1];
    int profit[n + 1];

    printf("Enter weight of items\n");
    for (i = 1; i <= n; i++){
        scanf("%d", &weight[i]);
    }

    printf("Enter profit of items\n");
    for (i = 1; i <= n; i++) {
        scanf("%d", &profit[i]);
    }

    printf("Enter capacity of knapsack: ");
    scanf("%d", &capacity);

    knapsack(capacity, n, weight, profit);

    return 0;
}
