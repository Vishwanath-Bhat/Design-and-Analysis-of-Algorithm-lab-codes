#include<stdio.h>
#include<stdlib.h>

int w[10],d,x[10];
void subset(int s,int k,int r){
    static int b = 1;
    x[k] = 1;
    if(s + w[k]  == d){
        printf("Solution %d :",b++);
        for(int i=1; i <= k; i++){
            if(x[i] == 1){
                printf("%d ", w[i]);
            }
        }
        printf("\n");
    }
    else if(s + w[k] + w[k+1] <= d) subset(s+w[k],k+1,r-w[k]);

    if((s + r - w[k] >= d) && (s + w[k+1] <= d)){
        x[k] = 0;
        subset(s,k+1,r-w[k]);
    }
}


int main(){
    int n;
    int sum = 0;
    scanf("%d",&n);
    
    for(int i = 1; i <= n; i++){
        scanf("%d", &w[i]);
        sum += w[i];
    }

    scanf("%d",&d);

    if(sum < d || w[1] > d){
        printf("No Solution\n");
    }
    subset(0,1,sum);
}