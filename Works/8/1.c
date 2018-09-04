#include<stdio.h>
void swap(int *x,int *y)
{
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}
int main()
{
    int a,b,c;
    int *m=&a,*n=&b,*p=&c;
    scanf("%d%d%d",&a,&b,&c);
    if(a>b) swap(m,n);
    if(b>c) swap(n,p);
    if(a>b) swap(m,n);
    printf("%d %d %d",*m,*n,*p);
    return 0;
}
