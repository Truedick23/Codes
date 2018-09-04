#include<stdio.h>
int main()
{
    int n,a[200000],i,t;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<=(n-1)/2;i+=2)
        {t=a[i];a[i]=a[n-1-i];a[n-1-i]=t;}
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");
    return 0;
}
