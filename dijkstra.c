#include <stdio.h>
#include <stdlib.h>

int d[10];

void dij(int a[10][10],int v[10],int src,int n){
    int u;
    for(int i = 1; i <= n; i++){
        int min = 999;
        for(int j = 1; j <= n; j++){
            if(v[j] == 0 && d[j] < min){
                min = d[j];
                u = j;
            }
        }
    
    v[u] = 1;
    for(int j = 1; j <= n; j++){
        if(v[j] == 0 && a[u][j] != 999 && d[j] > d[u] + a[u][j]){
            d[j] = d[u] + a[u][j];
        }
    }
    }
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
    scanf("%d",&source);

    for(int i = 1; i <= n; i++){
        d[i] = (i == source)? 0: 999;
        v[i] = 0;
    }

    dij(a,v,source,n);

    for(int i = 1; i <= n; i++){
        printf("source %d -> %d is %d \n",source,i,d[i]);
    }
}