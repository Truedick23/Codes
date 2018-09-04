#include<stdio.h>
#include<math.h>
double f(double x)
{
    double y;
    y=2*x*x*x-4+x*x+3*x-6;
    return y;
}

double d(double x)
{
    double y;
    y=6*x*x-8*x+3;
    return y;
}

int main()
{
    double n1,n2,t;
    n1=1.5;
    n2=1.5;
    while(fabs(n1-n2)<=0.0001)
    {
        t=n1;
        n1=n1+f(n1)/d(n1);
        n2=t;
    }
    printf("%f",n1);
    return 0;
}
