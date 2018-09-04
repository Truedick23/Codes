#include<stdio.h>
long gcd(long a,long b)
{
    long c,r;
    if(a<b)
    {
        c=a;a=b;b=c;                         //交换a,b，确保a>b
    }
    r=a%b;
    while(r!=0)
    {
        a=b;b=r;                             //实施辗转相除
        r=a%b;
    }
    return b;
}

void main()
{
    int k,n;
    long x,y,m[100];
    printf("Input the number of integers:");
    scanf("%d",&n);
    for(k=0;k<=n-1;k++)
    {
        printf("Please input No.%d integer: ",k+1);
        scanf("%ld",&m[k]);
    }
    x=m[0];
    for(k=1;k<=n-1;k++)
    {
        y=m[k];
        x=gcd(x,y);
    }
    printf("(%ld",m[0]);
    for(k=1;k<=n-1;k++)
    {
        printf(",%ld",m[k]);
    }
    printf(")=%ld\n",x);
}
