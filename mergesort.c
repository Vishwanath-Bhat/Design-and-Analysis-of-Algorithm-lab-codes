#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int count = 0;
#define SIZE 1000
void merge(int a[SIZE],int l,int m,int r){
    int i,j,k;
    i = l;
    j = m+1;
    k = l;
    int b[SIZE];
    while(i <=m && j <= r){
        if(a[i] < a[j]){
            b[k++] = a[i++];
            count++;
        }
        else{
            b[k++] = a[j++];
            count++;
        }
    }
    while(i <= m){
        b[k++] = a[i++];
        count++;
    }
    while(j <= r){
        b[k++] = a[j++];
        count++;
    }
    for(int i = l; i < k; i++){
        count++;
        a[i] = b[i];
    }
}

void mergesort(int a[SIZE],int l,int r){
    int m;
    if(l < r){
        m = (l + r)/2;
        mergesort(a,l,m);
        mergesort(a,m+1,r);
        merge(a,l,m,r);
    }
}

int main(){
    int n, a[SIZE],x[SIZE],y[SIZE],z[SIZE];
    int c1, c2, c3;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    mergesort(a,0,n-1);
    printf("Sorted array: ");
    for(int i = 0; i < n; i++){
        printf("%d ",a[i]);
    }
    printf("\n");

    for(int i = 16; i < SIZE; i*= 2){
         int ln = 2*i*log(i)/log(2);
        for(int j = 0; j < i; j++){
            x[j] = j;
            y[j] = i - j -1;
            z[j] = rand() % i;
        }
        count = 0;
        mergesort(x,0,i-1);
        c1 = count;

        count = 0;
        mergesort(y,0,i-1);
        c2 = count;

        count = 0;
        mergesort(z,0,i-1);
        c3 = count;

        printf("%d\t%d\t%d\t%d\t%d\t\n",i,c1,c2,c3,ln);
    }
}