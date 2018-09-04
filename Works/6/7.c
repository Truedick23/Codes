#include<stdio.h>
int main()
{
    int a[30][30];
    int m,n,i,t,i1,i2;
    scanf("%d",&t);
    for(i=1,m=0,n=(t-1)/2;i<=t*t;i++)
    {
        if(m-1>=0&&n+1<=t-1)
        {
            if(a[m-1][n+1]==0)
            {
                a[m=m-1][n=n+1]=i;
            }
            else
            a[m=m+1][n]=i;
        }
        if(m-1<0&&n+1<=t-1)
            a[m=t-1][n=n+1]=i;
        if(m-1>=0&&n+1>t-1)
            a[m=m-1][n=0]=i;
        if(m-1<0&&n+1>t-1)
            a[m=m+1][n]=i;
    }
    for(i1=0;i1<t;i1++)
    {
        for(i2=0;i2<t;i2++)
        {
            printf("%d ",a[i1][i2]);
        }
        printf("\n");
    }
    return 0;
}
