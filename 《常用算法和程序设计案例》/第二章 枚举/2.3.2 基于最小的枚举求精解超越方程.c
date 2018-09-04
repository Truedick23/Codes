/*  首先判断是否有解，x从a开始按步长量0.1递增取值，其函数值fny(x)与fny(b)作比较，若存在异号则有解，继续求解；
    然后设置函数最小值mi，通过fny(x)与mi相比较来求得最小值，用xi记录下来；
    然后进行逐步求精，即步长量缩小十分之一，改变循环范围*/

#include<stdio.h>
#include<math.h>
double fny(double x)
{
    return 2*pow(x,2)*pow(sin(x),7)+3*pow(x,0.5)*cos(x)-exp(x)/5;
}
void main()
{
    int k,t;
    double a,b,c,x,x1,y,mi;
    printf("Input a and b:");
    scanf("%lf,%lf",&a,&b);
    for(t=0,x=a;x<=b;x+=0.1)                         //按步长0.1初步扫描是否存在解
        if(fny(x)*fny(b)<=0)
        {
            t=1;break;
        }
    if(t==0)
    {
        printf("No solution!\n");return;
    }
    c=0.1;k=1;mi=100.0;
    while(k<=8)                                       //设置8次求精循环
    {
        for(x=a;x<=b;x+=c)
        {
            y=fny(x);
            if(fabs(y)<mi)                            //比较求取最小值mi
            {
                mi=fabs(y);x1=x;
            }
        }
        c=c/10;a=x1-5*c;b=x1+5*c;                      //缩小循环步长求精
        k++;
    }
    printf("x=%.8f\n",x1);
}
