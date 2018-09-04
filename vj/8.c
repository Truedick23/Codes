#include<stdio.h>
int main()
{
    int i1,i2,i3,l,n,a[100000],b[100000];
    scanf("%d",&n);
    for(i1=0;i1<n;i1++)
    {
        scanf("%d%d",&a[i1],&b[i1]);
    }
    for(i2=0,l=0;i2<n;i2++)
    {
        for(i3=n-1;i3>i2;i3--)
        {
            if(a[i2]<a[i3]&&b[i2]>b[i3])
                l++;
            if(a[i2]>a[i3]&&b[i2]<b[i3])
                l++;
        }
    }
    if(l)
        printf("Happy Alex\n");
    else
        printf("Poor Alex\n");
    return 0;
}
