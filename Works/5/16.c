#include<stdio.h>
int main()
{
    int n,i,t1,t2;
    scanf("%d",&n);
    for(t1=0;t1<n;t1++)
    {
        for(i=0;i<n-t1;i++)
            putchar(' ');
        for(i=1;i<2*t1;i++)
            putchar('*');
        putchar('\n');
    }
    for(t2=0;t2<n;t2++)
    {
        for(i=0;i<t2;i++)
            putchar(' ');
        for(i=1;i<2*(n-t2);i++)
            putchar('*');
        putchar('\n');
    }
    return 0;
}
