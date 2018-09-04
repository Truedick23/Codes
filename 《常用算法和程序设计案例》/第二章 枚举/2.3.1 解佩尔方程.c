//佩尔方程：x^2-ny^2=1
#include<stdio.h>
#include<math.h>
void main()
{
    double a,m,n,x,y;
    printf("Please input n in the equation \nx^2-ny^2=1:");
    scanf("%lf",&n);
    m=floor(sqrt(n+1));
    if(m*m==n)
    {
        printf("Not a square please.\n");
        return;
    }
    y=1;
    while(y<=10000000)
    {
        y++;                                //设置y从1开始递增枚举
        a=n*y*y;x=floor(sqrt(a+1));
        if(x*x==a+1)                        //检测是否满足方程
        {
            printf("Fundamental solution is: x=%.0f,y=%.0f\n",x,y);
            break;
        }
    }
    if(y>10000000)
        printf("No solution found!\n");
}
