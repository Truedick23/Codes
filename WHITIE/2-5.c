#include<stdio.h>
int main()
{
    freopen("2-5.txt","r",stdin);
    int n,m,a[1000],i,count=0;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
        if(a[i]<m)  count++;
    }
    printf("\n%d",count);
    return 0;
}
