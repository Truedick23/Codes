#include<stdio.h>
int main()
{
    long n,s,t;
    scanf("%ld",&n);
    s=0;t=1;
    while(t<=n)
    {
        t=t*5;s=s+n/t;
    }
    printf("%ld! have %ld zeros in total.\n",n,s);
    return 0;
}
