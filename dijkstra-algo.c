// dijkstra algorithm

#include <stdio.h>
#include <stdlib.h>
#define INFINITY 1000
int n; //This is for the number of vertices/nodes.
int distance[100]; //This is basically to keep distance of nodes from the source node.
int visited[100]; //This is to keep track whether a node is visited or not.
int cost[100][100]; //This is to keep the distance between two edges in given matrix.
int source;

int min_distance()
{
    int min = INFINITY;
    int min_index;

    for(int i=0;i<n;i++){
        if( !visited[i] && distance[i]<=min){
            min = distance[i];
            min_index = i;
        }
    }
    return min_index;
}

void printSolution()
{
    printf("Vertex and distance");
    for(int i=0;i<n;i++){
        printf("\n%d\t%d",i,distance[i]);
    }
}
void dijkstras()
{
    //First step is to make the distance from source as infinity and visited as 0;
    for(int v=0;v<n;v++){
        distance[v] = INFINITY;
        visited[v] = 0;
    }
    //Now wehave to mark the source distance as zero.
    distance[source] = 0;

    for(int i=0;i<n-1;i++){
        int min = min_distance();
        visited[min] = 1;

        for(int j=0;j<n;j++){
            if(!visited[j] && cost[min][j] && (distance[min] != INFINITY) && distance[j]>distance[min]+cost[min][j] ){
                distance[j] = distance[min] + cost[min][j];
            }
        }
    }

    printSolution();
}

int main()
{
    int i,j;
    printf("\nEnter the number of vertices:\t");
    scanf("%d",&n);

    printf("Enter the distance matrix");

    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            scanf("%d", &cost[i][j]);
        }
    }

    dijkstras();

    return 0;
}