#include<stdio.h>
#include<math.h>

int main()
{
    double a,b,c,delta;
    void x(double a,double b,double c);
    void y(double a,double b,double c);
    void z(double a,double b,double c);
    scanf("%lf%lf%lf",&a,&b,&c);
    delta=b*b-4*a*c;
    if(delta>0) x(a,b,delta);
    if(delta==0) y(a,b,delta);
    else z(a,b,delta);
    return 0;
}

void x(double a,double b,double c)
{
    double r,x1,x2;
    r=sqrt(c);
    x1=(-b+r)/2*a;
    x2=(-b-r)/2*a;
    printf("x1=%.3f\nx2=%.3f\n",x1,x2);
}

void y(double a,double b,double c)
{
    printf("x1=x2=%.3f",-b/2*a);
}

void z(double a,double b,double c)
{
    double r;
    r=sqrt(-c);
    printf("x1=%.2f+%.2fi/%.2f\nx2=%.2f-%.2fi/%.2f",-b,r,2*a,-b,r,2*a);
}
