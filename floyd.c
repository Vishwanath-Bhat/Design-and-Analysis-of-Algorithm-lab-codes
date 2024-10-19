#include<stdio.h>
#include<stdlib.h>
int mini(int a,int b)
{
    if(a<=b)
    {
        return a;
    }
    else
    {
        return b;
    }
}
void floyds(int a[][10],int N)
{
    for(int k=1;k<=N;k++)
    {
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=N;j++)
            {
                a[i][j]=mini(a[i][j],a[i][k]+a[k][j]);
            }
        }
    }
}
int main()
{
    int N,a[10][10];
    printf("\nenter the no of nodes: ");
    scanf("%d",&N);
    printf("\nenter the adjacency matrix of the graph:\n");
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            scanf("%d",&a[i][j]);
        }
        printf("\n");
    }
    floyds(a,N);
    printf("\n the all pair shortest path is\n");
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}