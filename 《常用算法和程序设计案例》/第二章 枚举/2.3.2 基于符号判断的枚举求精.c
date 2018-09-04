/*  首先进行判断是否有解，即x从开始递增取值，其值与fny(b)比较，遇到异号时将此时x的值赋给x1，b赋给x2;
    然后逐位求精，每次c变为十分之一，使fny(x)与fny(x2)比较：
    若产生异号，且下一点同号，则作赋值：x2=x,x1=x-c*/


#include<stdio.h>
#include<math.h>
double fny(double x)
{
    return 2*pow(x,2)*pow(sin(x),7)+pow(x,0.5)*cos(x)-exp(x)/5;
}
void main()
{
    int i,t=0;
    double a,b,x,x1,x2,c;
    printf("Input a and b:");
    scanf("%lf%lf",&a,&b);
    for(x=a;x<=b;x+=0.1)                //初步扫描，确定初始位置
        if(fny(x)*fny(b)<=0)
    {
        x1=x;x2=b;t=1;break;
    }
    if(t==0)
    {
        printf("No Solution!");
        return;
    }
    c=0.01;
    for(i=2;i<=9;i++)                     //逐步求精
    {
        for(x=x1;x<=x2;x+=c)
            if(fny(x)*fny(x2)>0)           //如果变为同号，缩小循环范围
        {
            x2=x;x1=x-c;break;              //调整初值和终值
        }
        c=c/10;                             //缩小循环步长求精
    }
    x=(x1+x2)/2;
    printf("x=%.8f",x);
}
