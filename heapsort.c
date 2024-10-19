#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int count = 0;
#define SIZE 1000
int len = 0;
int a[SIZE];

void heapify(int i){
    int k,v,flag,j;
    k = i;
    v = a[k];
    flag = 0;
    while(!flag && 2*k <= len){
        j = 2*k;
        if(j < len){
            count++;
            if(a[j] < a[j+1]) j++;
        }
        count++;
        if(v >= a[j]) flag = 1;
        else{
            a[k] = a[j];
            k = j;
        }
    }
    a[k] = v;
}



void heap(){
    int temp;
    for(int i = len/2; i > 0; i--){
        heapify(i);
    }

    for(int i = len; i>=2; i--){
        count++;
        temp = a[1];
        a[1] = a[len];
        a[len] = temp;
        len--;
        heapify(1);
    }
}
int main(){
    int n,x[SIZE],y[SIZE],z[SIZE];
    int c1, c2, c3;
    scanf("%d", &n);
    len = n;
    for(int i = 1; i <= len; i++){
        scanf("%d", &a[i]);
    }
    heap();
    printf("Sorted array: ");
    for(int i = 1; i <= n; i++){
        printf("%d ",a[i]);
    }
    printf("\n");

    for(int i = 16; i < SIZE; i*= 2){
         int ln = 2*i*log(i)/log(2);

        count = 0;
        len = i;
        for(int j = 1; j <= i; j++){
            a[j] = j;
        }
        heap();
        c1 = count;

        count = 0;
        len = i;
        for(int j = 1; j <= i; j++){
            a[j] = i - j - 1;
        }
        heap();
        c2 = count;

        count = 0;
         len = i;
        for(int j = 1; j <= i; j++){
            a[j] = rand() % i;
        }
        heap();
        c3 = count;

        printf("%d\t%d\t%d\t%d\t%d\t\n",i,c1,c2,c3,ln);
    }
}