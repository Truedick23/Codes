#include<stdio.h>
int main()
{
    int n,m;
    for(n=2;n<=100;n++)
    {
        for(m=n-1;m>=1;m--)
        {
            if(n%m==0)
                break;
        }
        if(m==1)
        {
            printf("%d,",n);
        }
    }
    printf("\b");
    return 0;
}
