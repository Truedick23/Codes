#include<stdio.h>
int main()
{
    int m,n;
    int a(int x,int y);
    int b(int x,int y);
    scanf("%d%d",&m,&n);
    printf("%d\n%d\n",a(m,n),b(m,n));
}

int a(int x,int y)
{
    int l;
    while(y%x!=0)
    {
        x=y%x;
    }
    return x;
}

int b(int x,int y)
{
    int c,d;
    c=x/a(x,y);
    d=y/a(x,y);
    return a(x,y)*c*d;
}
