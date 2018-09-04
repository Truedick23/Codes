#include<stdio.h>
int main()
{
    int n,i,m=n;
    while(scanf("%d",&n)!=0)
    {

        for(;n>0;n--)
        {
            for(i=m;i>n;i--)
            {
                printf(" ");
            }
            for(i=2*n-1;i>0;i--)
            {
                printf("#");
            }
            printf("\n");
        }
    }
    return 0;
}
