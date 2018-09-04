#include<stdio.h>
int main()
{
    double n,sum=0;
    int i;
    scanf("%lf",&n);
    for(i=1;i<=n;i++)
    {
        sum+=1.0/i;
    }
    printf("%.3f",sum);
    return 0;
}
