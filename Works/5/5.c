#include<stdio.h>
#include<math.h>
int one(double x)
{
    double sum,i,y,t=10;
    for(i=0,sum=0;i<x;i++)
    {
        y=pow(t,i);
        sum=sum+y;
    }
    return sum;
}
int main()
{
    int s=0,a,n,i1,i2,b,bb=0;
    scanf("%d%d",&a,&n);
    for(i1=0;i1<=n;i1++)
    {
        for(i2=0;i2<=i1;i2++)
        {
            b=one(i2);
            bb=bb+b;
        }
        printf("%d+",bb);
        s=s+bb;
    }
    s=s*2;
    printf("\b=%d",s);
    return 0;
}
