#include<stdio.h>
int main()
{
    int i;
    float sum,a,m,n,t;
    for(i=0,sum=0,m=1,n=2;i<20;i++)
    {
        printf("%.0f/%.0f+",n,m);
        a=n/m;
        t=m;
        m=n;
        n=t+n;
        sum=sum+a;
    }
    printf("\b=%f",sum);
    return 0;
}
