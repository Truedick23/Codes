#include<stdio.h>
int main()
{
    int m,n,i;
    scanf("%d%d",&m,&n);
    while(m%n!=0)
    {
        i=n;
        n=m%n;
        m=i;
    }
    printf("%d",n);
    return 0;
}
