#include<stdio.h>
void sort(int a[],int n)
{
    int i1,i2,t;
    for(i1=0;i1<n-1;i1++)
        for(i2=i1+1;i2<n;i2++)
    {
        if(a[i2]>a[i1])   {t=a[i1];a[i1]=a[i2];a[i2]=t;}
    }
}

int max(int a[],int n)
{
    int max=a[0],i;
    for(i=0;i<n;i++)
    {
        if(max<a[i])    max=a[i];
    }
}
int main()
{
    int a[1000],b[1000],n,d,i,t=0,i1,i2,p;
    scanf("%d",&n);
    p=n;
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++)
    {
        b[t]=a[i];
        t++;
        if(a[i]==p)
        {
            sort(b,t);
            for(i1=0;i1<t;i1++)
                {printf("%d ",b[i1]);b[i1]=0;}
            p-=max(b,t);t=0;
        }
        printf("\n");
    }
    return 0;
}


