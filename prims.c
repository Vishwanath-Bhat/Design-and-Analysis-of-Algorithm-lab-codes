#include <stdio.h>
#include <stdlib.h>

void prims(int a[10][10],int vis[10],int n){
    int min,mincost = 0, e =1;
    int u, v;
    for(int i = 1; i <=n; i++){
        vis[i] = 0;
    }
    vis[1] = 1;
    while(e < n){
        min = 999;
        for(int i = 1; i <= n; i++){
            if(vis[i]){
                for(int j = 1; j <= n; j++){
                    if(!vis[j] && a[i][j] < min){
                        min = a[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }
        if(!vis[v]){
            mincost += min;
            printf("Edge %d (%d %d): cost -> %d\n",e++,u,v,min);
            vis[v] = 1;
        }
        a[u][v] = a[v][u] = 999;  
    }
    printf("Toatal cost: %d",mincost);
}

int main(){
    int a[10][10],v[10];
    int n;
    int source;
    printf("Enter the number of vertices: ");
    scanf("%d",&n);
    printf("Enter the Cost Adjacency matrix (999 for no connection):\n");
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            scanf("%d", &a[i][j]);
        }
    }
   
    prims(a,v,n);
}