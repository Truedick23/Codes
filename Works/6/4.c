#include<stdio.h>
int main()
{
    int a[11]={87,23,12,54,9,23,100,3,23,1023,77};
    int i,j,t;
    for(i=1;i<11;i++)
    {
        t=a[i];
        for(j=i-1;j>=0&&t>a[j];j--)
        {
            a[j+1]=a[j];
            a[j+1]=t;
        }
     }
    for(i=0;i<11;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}
