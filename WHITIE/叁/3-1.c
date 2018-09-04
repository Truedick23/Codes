#include<stdio.h>
#include<string.h>
int main()
{
    int a[100],x,max,i=0,p;
    memset(a,0,sizeof(a));
    while(scanf("%d",&x)!=EOF)
    {
        a[x]++;
    }
    for(i=0,max=a[0],p=0;i<=100;i++)
    {
        if(a[i]>max)    max=a[i],p=i;
    }
    printf("%d",max);
    return 0;
}
