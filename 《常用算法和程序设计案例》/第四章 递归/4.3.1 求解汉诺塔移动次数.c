/*  对于n个圆盘从A桩全部移到C桩的移动次数：
    当n=1时，一个盘移动一次即完成
    当n=2时，由于条件规定只能移动一个盘，且不允许大盘在小盘之上，则：
    设移动n个盘的汉诺塔需g(n)次完成。分以下3个步骤：
    (1) 将n个盘上面的n-1个盘子借助C桩从A桩移动到B桩上，需g(n-1)次
    (2) 将A桩上的第n个盘子移到C桩上(1次)
    (3) 将B桩上的n-1个盘子借助A桩移到C桩上，需要g(n-1)次
    故有以下递推：
            g(n)=2*g(n-1)+1
    */

#include<stdio.h>
void main()
{
    double g(int m);
    int n;
    printf(" Input the number of plate(s) n: ");scanf("%d",&n);
    if(n<=40)
        printf(" No.%d have been moved %.0f\n times.\n",n,g(n));
    else
        printf(" N0.%d have been moved %.4e\n times.\n",n,g(n));
}

double g(int m)
{
    double s;
    if(m==1)
        s=1;
    else
        s=2*g(m-1)+1;
    return s;
}
