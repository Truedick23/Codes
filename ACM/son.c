#include<stdio.h>
int main()
{
    int n,i,a[1000],t;
    scanf("%d",&n);
    int p,q;
    for(t=0;t<n;t++)
    {
        scanf("%d%d",&p,&q);
        a[p]=q;
    }
    scanf("%d",&i);
    while(a[i]!=i)
    {
        printf("%d ",i);
        i=a[i];
    }
    printf("%d",a[i]);
    return 0;
}
