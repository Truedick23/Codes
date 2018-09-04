/*设整数a的小于其本身的因数之比为s，定义 p(a)=s/a 为整数的因数比，求其最大值*/

#include<stdio.h>
#include<math.h>
void main()
{
    double a,s,a1,s1,b,k,t,x,y,max=0;
    printf("Input x and y:");
    scanf("%lf%lf",&x,&y);
    for(a=x;a<=y;a++)                       //枚举区间内所有整数
    {
        s=1;b=sqrt(a);
        for(k=2;k<=b;k++)                   //试商寻求a的因数k
            if(fmod(a,k)==0)
                s=s+k+a/k;                  //因数求和
        if(a==b*b)  s=s-b;                  //若a=b^2，去掉重复因数b
        t=s/a;
        if(max<t)
        {
            max=t;a1=a;s1=s;
        }
    }
    printf("The maximum sum of integer %.0f is: %.4f\n",a1,max);
    printf("    %.0f have the sum of:\n",a1);
    printf("    %.0f=1",s1);
    for(k=2;k<=a1/2;k++)
        if(fmod(a1,k)==0)
        printf("+%.0f",k);
}

