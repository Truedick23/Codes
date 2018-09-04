#include<stdio.h>
int main()
{
    int n,k;
    while(scanf("%d",&n)!=EOF)
    {
        k=1;
        if(k%3==0&&k%2==0)
            k=1;
        if(k%3!=0&&k%2!=0)
            k=1;
        if(k%3==0&&k%2!=0)
            k=0;
        if(k%3!=0&&k%2==0)
            k=0;

    }
}
