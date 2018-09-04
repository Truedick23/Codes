/*最简真分数定义：分子小于分母，且分子分母无公因数*/

#include<stdio.h>
#include<math.h>
void main()
{
    int a,b,i,j,t,u;long m=0;
    double s;
    printf("Please input a and b, and the denominator is between [a,b]:");    //输入区间上下限
    scanf("%d%d",&a,&b);
    s=0;
    for(j=a;j<=b;j++)                                   //枚举分母
    for(i=1;i<=j-1;i++)                                 //枚举分子
    {
        for(t=0,u=2;u<=i;u++)                           //枚举因数
        if(j%u==0&&i%u==0)
        {
            t=1;break;                                  //分子分母有公因数,舍去
        }
        if(t==0)
        {
            m++;                                        //统计最简真分数个数
            s+=(double)i/j;                             //求最简真分数的和
        }
    }
    printf("There are %d in total.\n",m);
    printf("Sum=%.5f\n",s);
}
