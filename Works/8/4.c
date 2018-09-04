#include<stdio.h>
void move(int a[],int n,int m)
{
    int t[100],i=0;
    int *p;
    for(p=a;p<a+n-m;p++,i++)
    {
        t[i]=*p;
    }
    for(p=a+n-m,i=0;p<(a+n);p++,i++)
    {
        a[i]=*p;
    }
    for(p=a+n-m,i=0;p<(a+n);p++,i++)
    {
        *p=t[i];
    }
}
int main()
{
    int a[100],m,n,*p;
    scanf("%d%d",&n,&m);
    for(p=a;p<(a+n);p++)
    {
        scanf("%d",p);
    }
    move(a,n,m);
    for(p=a;p<(a+n);p++)
    {
        printf("%d ",*p);
    }
}
