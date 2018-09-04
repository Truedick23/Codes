#include<stdio.h>
#include<math.h>
int main()
{
    int a,m,n;
    for(a=1;a<=1000;a++)
    {
        for(m=1,n=0;m<=a/2;m++)
        {
            if(a%m==0)
            {
                n=n+m;
            }
        }


        if(n==a)
        {
            printf("%d its factors are ",a);
            for(m=1;m<sqrt(a)+1;m++)
            {
                if(a%m==0)
                {
                    printf("%d,",m);
                }
            }
            printf("\b \n");
        }
    }
    return 0;
}
