#include<stdio.h>
int main()
{
    int i,m,n,z;
    scanf("%d%d%d",&m,&n,&z);
    printf("%d\n",z/r(m,n));
    return 0;
}

int r(int m,int n)
{
    int t,l,i,re;
    t=m>n?m:n;
    for(i=1;i<=t;i++)
        if(m%i==0&&n%i==0)  re=i;
    return m*n/re;
}
