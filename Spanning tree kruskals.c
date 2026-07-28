#include <stdio.h>
#include <stdlib.h>
#include <limits.h>



void kruskalMST(int **cost, int V) {

int parent[100];
for (int i = 0; i < V; i++)
    parent[i] = i;

int edgeCount = 0, minCost = 0;

while (edgeCount < V - 1) {
    int min = INT_MAX, u = -1, v = -1;

    for (int i = 0; i < V; i++) {
        for (int j = i + 1; j < V; j++) {
            if (cost[i][j] != 0 && cost[i][j] < min) {
                min = cost[i][j];
                u = i;
                v = j;
            }
        }
    }

    int a = u, b = v;
    while (parent[a] != a) a = parent[a];
    while (parent[b] != b) b = parent[b];

    if (a != b) {
        printf("Edge %d:(%d, %d) cost:%d\n",edgeCount, u, v, min);
        minCost += min;
        parent[a] = b;
        edgeCount++;
    }

    cost[u][v] = cost[v][u] = INT_MAX;
}

printf("Minimum cost= %d\n", minCost);
}


int main() {
    int V;
    printf("No of vertices: ");
    scanf("%d", &V);

    int **cost = (int **)malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++)
        cost[i] = (int *)malloc(V * sizeof(int));

    printf("Adjacency matrix:\n");
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            scanf("%d", &cost[i][j]);

    kruskalMST(cost, V);

    for (int i = 0; i < V; i++)
        free(cost[i]);
    free(cost);

    return 0;
}
