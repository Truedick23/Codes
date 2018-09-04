#include<stdio.h>
int main()
{
    int n,i;
    double x,res;
    double p(int m,double n);
    scanf("%d%lf",&n,&x);
    res=p(n,x);
    printf("%f",res);
    return 0;
}

double p(int m,double n)
{
    double result;
    if(m==0)
    {
        result=1;
    }
    if(m==1)
    {
        result=n;
    }
    if(m>=2)
    {
        result=((2*m-1)*n-p(m-1,n)-(m-1)*p(m-2,n))/n;
    }
    return result;
}
