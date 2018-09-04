#include<stdio.h>
#include<math.h>
int main()
{
    int i,sum=0,n,m,a,b,c;
    for(i=100;i<1000;i++)
    {
        m=i;
        a=i/100;
        b=(i-100*a)/10;
        c=i%10;
        sum=a*a*a+b*b*b+c*c*c;
        if(sum==m)  printf("%5d",m);
    }
    return 0;
}
