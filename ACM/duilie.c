#include<stdio.h>

int main()
{
    int a[1000000],i,t,m=0,n=0;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        a[n++]=i;
    }

    while(n-m>2)
    {
        printf("%d",a[m]);
        m++;
        a[n]=a[m];
        n++;
        m++;
    }
    printf("%d%d",a[m],a[n]);
    return 0;
}
