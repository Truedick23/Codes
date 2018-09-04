#include<stdio.h>
#include<math.h>
int main()
{
    int a;
    double x1,x2,t;
    scanf("%d",&a);
    x1=1;
    while(fabs(x2-x1)>=0.000001)
    {
        t=x1;
        x1=(x1+a/x1)/2;
        x2=t;
    }
    printf("%f",x1);
    return 0;
}
