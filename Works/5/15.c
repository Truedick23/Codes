#include<stdio.h>
#include<math.h>
double f(double x)
{
    double y;
    y=2*x*x*x-4*x*x+3*x-6;
    return y;
}

int main()
{
    double n1=10,n2=-10,t,m;
    while(fabs(n1-n2)>1e-5)
    {
        m=(n1+n2)/2;
        if(f(m)==0)
            break;
        if(f(m)*f(n1)<0)
        {
            n2=m;
        }
        else
        {
            n1=m;
        }

    }
    printf("%f",m);
    return 0;
}
