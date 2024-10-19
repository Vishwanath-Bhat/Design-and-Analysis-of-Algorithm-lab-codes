#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int count = 0;
#define SIZE 1000

int partition(int a[SIZE],int l, int r){
    int i,j,temp,pivot;
    pivot = a[l];
    i = l +1;
    j = r;

    while(1){
        while(pivot >= a[i] && i <= r){
            i++;
            count++;
        }
        while(pivot < a[j] && j != l){
            j--;
            count++;
        }
        if(i < j){
            temp = a[i];
            a[i]  = a[j];
            a[j] = temp;
        }else{
            temp = a[l];
            a[l]  = a[j];
            a[j] = temp;
            return j;
        }
    }
    return - 1;
}

void quicksort(int a[SIZE],int l,int r){
    if(l < r){
        int s = partition(a,l,r);
        quicksort(a,l,s-1);
        quicksort(a,s+1,r);
    }
}

int main(){
    int n, a[SIZE],x[SIZE],y[SIZE],z[SIZE];
    int c1, c2, c3;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    quicksort(a,0,n-1);
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
        quicksort(x,0,i-1);
        c1 = count;

        count = 0;
        quicksort(y,0,i-1);
        c2 = count;

        count = 0;
        quicksort(z,0,i-1);
        c3 = count;

        printf("%d\t%d\t%d\t%d\t%d\t\n",i,c1,c2,c3,ln);
    }
}