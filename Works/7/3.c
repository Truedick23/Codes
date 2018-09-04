#include<stdio.h>
int main()
{
    int a;
    void pr(int x);
    while(scanf("%d",&a)!=EOF)
    {
        pr(a);
    }
    return 0;
}

void pr(int x)
{
    int i;
    if(x<=1)    printf("Error!\n");
    else
    {
        for(i=2;i<=(x+1)/2;i++)
        {
            if(x%i==0)  break;
        }
        if(i>(x+1)/2)    printf("The number is a prime number\n");
        else    printf("The number is not a prime number\n");
    }
    }

