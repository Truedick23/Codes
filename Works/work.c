#include<stdio.h>
int main()
{
    int a[20];
    int i=10,m,t,j;
    for(m=0;m<i;m++)
    {
        if(a[m]<a[m+1])
        {
            t=a[m];
            a[m]=a[m+1];
            a[m+1]=t;
        }
    }
}
