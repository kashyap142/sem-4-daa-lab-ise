#include <stdio.h>
int a[20][20], q[20], visted[20], n, i, j, f = 0, r = -1;

void bfs(int v)
{
    for (i = 1; i <= n; i++)
    {
        if (a[v][i] && !visted[i])
        {
            q[++r] = i;
        }
    }
    if (f <= r)
    {
        visted[q[f]] = 1;
        bfs(q[f++]);
    }
}

void main()
{
    int v;
    printf("enter the number of vertices\n");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        q[i] = 0;
        visted[i] = 0;
    }

    printf("adjacency Matrix\n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);

    printf("\n");

    printf("enter the starting vertex\n");
    scanf("%d", &v);
    bfs(v);
    printf("the reachable nodes are\n");
    for (i = 1; i <= n; i++) {
        if (visted[i])
            printf("%d\t", i);
        else
            printf("BFS Not possible");
    }
        
}