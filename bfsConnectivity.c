#include <stdio.h>
#include <stdlib.h>

void bfs(int a[10][10], int v[10], int n,int src){
    int q[10], f = 0, r = -1;
    v[src] = 1;
    q[++r] = src;

    while( f <= r){
        int node = q[f++];
        for(int i=1; i <= n; i++){
            if(v[i] == 0 && a[node][i] == 1){
                v[i] = 1;
                q[++r] = i;
            }
        }
    }
}


int main()
{
   int n, i, j, a[10][10];
   printf("\n Enter the number of nodes: ");
   scanf("%d", &n);
   printf("\n Enter the adjacency matrix:\n");
   for (i = 1; i <= n; i++)
   {
      for (j = 1; j <= n; j++)
      {
         scanf("%d", &a[i][j]);
      }
   }
   int vis[10];
   for (int i = 1; i <= n; i++)
   {
      vis[i] = 0;
   }
   int count = 0;
   for(int i = 1; i <= n; i++){
        if (vis[i] == 0) {
            bfs(a, vis, n, i);
            count++;
        }
   }
   if (count == 1)
        printf("\nThe graph is connected\n");
    else
        printf("\nThe graph is not connected and has %d componenets\n", count);
    return 0;
}