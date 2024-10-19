#include <stdio.h>
#include <stdlib.h>

int topo[10];
int cycle = 0;
int k = 0;

void dfs(int a[10][10], int v[10], int n,int src){
    v[src] = 1;
    for(int i = 1; i <= n; i++){
        if(a[src][i] == 1){
            if(v[i] == 1){
                cycle = 1;
                return;
            }
            if(v[i] == 0){
                dfs(a,v,n,i);
                if(cycle == 1) return;
            }
        }
    }
    v[src] = 2;
    topo[++k] = src;
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

   for(int i = 1; i <= n; i++){
        if (vis[i] == 0) {
            dfs(a, vis, n, i);
            if (cycle == 1) break; // Exit if a cycle is detected
        }
   }
   if(cycle==1)
      printf("Cycle detected\n");

      else
      {
        for(int i=k;i>=1;i--)
        {
            printf("%d\t",topo[i]);
        }
      }
   
   return 0;
}