#include<stdio.h>
int prime(int a)
{
    int i,k=1;
    for(i=2;i<a;i++)
        if(a%i==0)  k=0;
    return k;
}
int q(int a,int b)
{
    int k=0;
    if(a!=b&&b%a==0)    k=1;
    return k;
}

int main()
{
    int n,i,a[100000],color[100000],i1,i2,kind=1,bigger;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        color[i]=1;
    for(i=0;i<n;i++)
        a[i]=i+2;
    for(i1=0;i1<n;i1++)
        for(i2=0;i2<n;i2++)
            if(q(a[i1],a[i2]))
            {
                bigger=color[i1]>color[i2]?i1:i2;
                color[bigger]++;
            }
    for(i=0;i<n;i++)
        if(color[i]>kind)   kind=color[i];
    printf("%d\n",kind);
    for(i=0;i<n;i++)
        printf("%d ",color[i]);
    printf("\n");
    return 0;
}
