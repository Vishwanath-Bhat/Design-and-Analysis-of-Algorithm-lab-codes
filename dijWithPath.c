#include <stdio.h>
#include <stdlib.h>

int d[10];        // Stores the shortest distance from the source
int parent[10];   // Stores the parent of each node in the shortest path

void printPath(int dest) {
    if (parent[dest] == -1) {
        printf("%d ", dest);
        return;
    }
    printPath(parent[dest]);
    printf("-> %d ", dest);
}

void dij(int a[10][10], int v[10], int src, int n) {
    int u;
    for (int i = 1; i <= n; i++) {
        int min = 999;
        for (int j = 1; j <= n; j++) {
            if (v[j] == 0 && d[j] < min) {
                min = d[j];
                u = j;
            }
        }

        v[u] = 1;
        for (int j = 1; j <= n; j++) {
            if (v[j] == 0 && a[u][j] != 999 && d[j] > d[u] + a[u][j]) {
                d[j] = d[u] + a[u][j];
                parent[j] = u; // Set the parent of j to u
            }
        }
    }
}

int main() {
    int a[10][10], v[10];
    int n, source;
    
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    
    printf("Enter the Cost Adjacency matrix (999 for no connection):\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter the source vertex: ");
    scanf("%d", &source);

    for (int i = 1; i <= n; i++) {
        d[i] = (i == source) ? 0 : 999;
        v[i] = 0;
        parent[i] = -1; // Initialize parent as -1 (no parent)
    }

    dij(a, v, source, n);

    for (int i = 1; i <= n; i++) {
        if (d[i] == 999) {
            printf("No path from %d to %d\n", source, i);
        } else {
            printf("Shortest distance from %d to %d is %d\n", source, i, d[i]);
            printf("Path: ");
            printPath(i);
            printf("\n");
        }
    }

    return 0;
}
