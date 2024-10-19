#include<stdio.h>
#include<stdlib.h>

static int c = 1;
int x[10];


void print(int n){
    printf("Solution %d :\n",c++);
    for(int i=1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(x[i] == j){
                printf("Q ");
            }else{
                printf("_ ");
            }
        }
        printf("\n");
    }
}

int place(int k,int i){
    for(int j = 1; j < k; j++){
        if((x[j] == i) || abs(x[j] - i) == abs(j - k)){
            return 0;
        }
    }
    return 1;
}

void nqueen(int k,int n){
    for(int i = 1; i<= n; i++){
        if(place(k,i)){
            x[k] = i;
            if(k == n){
                print(n);
                printf("\n");
            }
            else{
                nqueen(k+1,n);
            }
        }
    }
}

int main(){
    int n;
    scanf("%d",&n);
    nqueen(1,n);
    if(c == 1) printf("No solution\n");
    return 0;
}