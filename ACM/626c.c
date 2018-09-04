#include<stdio.h>
int main()
{
    int a,b,i,m[1000],n[1000];
    int max(int a,int b);
    scanf("%d%d",&a,&b);
    a+=b/2;
    b+=a/3;
    if(a>=3)    b--;
    printf("%d",max(a*2,b*3));
}

int max(int a,int b)
{
    return a>b? a:b;
}
