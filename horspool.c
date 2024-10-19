#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int count = 0;
#define SIZE 256
int len = 0;
int Table[SIZE];

void shiftTable(char p[10]){
    int m= strlen(p);
    for(int i = 0; i < 256; i++){
        Table[i] = m;
    }
    for(int i = 0; i < m-1; i++){
        Table[p[i]] = m - i - 1;
    }
}

int horspool(char t[100], char p[10]){
    int m = strlen(p);
    int n = strlen(t);
    int i = m - 1;
    int k;
    shiftTable(p);

    while(i <= n -1){
        k = 0;
        while(k < m && p[m-1-k] == t[i - k]) k++;

        if(k == m) {
            return i - m + 1;
        }
        else {
            i = i + Table[t[i]];
        }
    }
    return -1;
}

int main(){
    char t[100], p[10];
    scanf("%[^\n]",t);
    scanf("%s",p);
    int flag = horspool(t, p);
    if (flag == -1)
        printf("\nPattern not present in the text\n");
    else
        printf("Pattern is found at index %d\n", flag);
    return 0;
}