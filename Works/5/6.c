#include<stdio.h>
int main()
{
    int i,t,n,sum=0,r;
    for(i=1;i<=20;i++)
    {
        for(t=1,r=1;t<=i;t++)
        {
            r=r*t;
        }
        sum=sum+r;
    }
    printf("%d",sum);
    return 0;
}
