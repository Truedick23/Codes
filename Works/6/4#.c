#include<stdio.h>
int main()
{
    int a[10]={89,23,12,123,4,53,81,111,41,2};
    int t,p,i;
    for(i=1;i<10;i++)
    {
        t=a[i];
        p=i-1;
        while(p>=0&&t<a[p])
        {
            a[p+1]=a[p];
            p--;
        }
        a[p+1]=t;
    }
    for(i=0;i<10;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}
