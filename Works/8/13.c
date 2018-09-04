#include<stdio.h>
#include<math.h>
#define MIN 0.000001

double f1(double x)
{
    return (1+x);
}

double f2(double x)
{
    return (2*x+3);
}

double f3(double x)
{
    return (exp(x)+1);
}

double f4(double x)
{
    return (x*x+2*x+1);
}

double f5(double x)
{
    return (x*x*x);
}

double f6(double x)
{
    return (sin(x));
}

double f7(double x)
{
    return (cos(x));
}

double f8(double x)
{
    return (exp(x));
}

int main()
{
    double a,b;
    int choice;
    double(*p)(double );
    double func(double x,double y, double(*p)(double ));
    printf("Please choose the number of the function and entry a&b:\n");
    scanf("%d%lf%lf",&choice,&a,&b);
    switch(choice)
    {
        case 1:p=f1;break;
        case 2:p=f2;break;
        case 3:p=f3;break;
        case 4:p=f4;break;
        case 5:p=f5;break;
        case 6:p=f6;break;
        case 7:p=f7;break;
        case 8:p=f8;break;
    }
    printf("%f\n",func(a,b,p));
    return 0;
}

double func(double x,double y,double(*p)(double))
{
    double i,result=0,f;
    for(i=x;i<y;i+=MIN)
    {
        f=((*p)(i+MIN)+(*p)(i))*MIN/2;
        result+=f;
    }
    return (result);
}
