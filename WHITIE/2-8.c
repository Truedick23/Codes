#include<stdio.h>
int main()
{
    long n,m;
    double sum;
    scanf("%d%d",&n,&m);
    for(;n<=m;n++)
    {
        sum+=1.0/n/n;
    }
    printf("%.5f\n",sum);
    return 0;
}
