#include<stdio.h>
#include<stdlib.h>

int w[10],v[10],V[10][10],x[10],W,n;

int max(int a, int b)
{
    return (a > b) ? a : b;
}

void display(int n,int W){
    int i = n;
    int j = W;
    while(i > 0 || j > 0){
        if(V[i][j] != V[i-1][j]){
            x[i] = 1;
            j = j - w[i];
        }
        i--;
    }
}

int main(){
    int n;
    scanf("%d",&n);
    printf("weigths\n");
    for(int i = 1; i <= n; i++){
        scanf("%d", &w[i]);
    }
    printf("Value\n");
    for(int i = 1; i <= n; i++){
        scanf("%d", &v[i]);
    }
    scanf("%d",&W);
    for(int i=0; i <= n; i++){
        for(int j = 0; j <= W; j++){
            if(i == 0 || j == 0){
                V[i][j] = 0;
            }else{
                V[i][j] = (j - w[i] < 0)? V[i-1][j]: max(V[i-1][j],V[i-1][j - w[i]] + v[i]);
            }
        }
    }
    printf("Profit %d ",V[n][W]);
    display(n,W);
    for(int i = 1; i<= n; i++){
        if(x[i] == 1) printf("%d ",w[i]);
    }
}