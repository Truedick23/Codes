#include<stdio.h>
int main()
{
    int a,b,c,max;
    scanf("%d%d%d",&a,&b,&c);
    if(a<b)
    {
        if(c>b)
            max=c;
        else
            max=b;
    }
    else
    {
        if(c>a)
            max=c;
        else
            max=a;
    }
    printf("%d",max);
    return 0;
}
