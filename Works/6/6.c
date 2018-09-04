#include<stdio.h>
int main()
{
    int a[255][255];
    int m,n,i,b;
    scanf("%d",&b);
    for(i=0;i<b;i++)
    {
        a[i][0]=1;
        a[i][i]=1;
    }
        for(m=1;m<b;m++)
    {
        for(n=1;n<m;n++)
        {
            a[m][n]=a[m-1][n-1]+a[m-1][n];
        }
    }

    for(m=0;m<b;m++)
    {
        for(i=0;i<b-m;i++)
            putchar(' ');
        for(n=0;n<=m;n++)
        {
            printf("%d ",a[m][n]);
        }
        printf("\n");
    }
    return 0;
}
