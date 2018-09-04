/*  一个泼猴沿着一座小山的n级台阶向上跳，一步有m种跨法，一步跨若干级，均从键盘输入
    试求上山的n级台阶有多少种不同的爬法

    实现算法：
    设爬山t级台阶的不同爬法为f[t]，设从键盘输入的m个整数分别为x[1],x[2],...,x[m](约定从小到大排列)
    探讨f[t]的递推关系：
    当t<x[1]时，f[t]=0,f[x[1]]=1.
    当x[1]<t<=x[2]时，第一级递推: f[t]=f[t-x[1]].
    当x[2]<t<=x[3]时，第二级递推: f[t]=f[t-x[1]]+f[t-x[2]].
    …………
    一般地，当x[k]<t<=x[k+1],k=1,2,……,m-1，有第k级递推：
        f[t]=f[t-x[1]]+f[t-x[2]]+……+f[t-x[k]]
    当t=x[m](m=1,2,3,....)时，按上递推求f[t]外，还要加上1，因为此时可以有一步到位
    */

#include<stdio.h>
void main()
{
    int i,j,k,m,n,t,x[10];
    long f[200];
    printf("Input the number of stairs: ");scanf("%d",&n);
    printf("Input the number of methods: ");scanf("%d",&m);
    for(i=1;i<=m;i++)
    {
       printf("Input the No.%d method: ",i);
       scanf("%d",&x[i]);
    }
    for(i=1;i<=x[1]-1;i++)  f[i]=0;                 //第一种情况，即t<x[1]时
    x[m+1]=n;f[x[1]]=1;                             //设置初始条件
    for(k=1;k<=m;k++)
    for(t=x[k]+1;t<=x[k+1];t++)
    {
        f[t]=0;
        for(j=1;j<=k;j++)
            f[t]=f[t]+f[t-x[j]];                //按公式递推类加
        if(t==x[k+1])                           //t=x[k+1]时增加1
            f[t]=f[t]+1;
    }
    printf(" The number of methods in total is: ");
    printf("%d(%d",n,x[1]);
    for(i=2;i<=m;i++)
        printf(",%d",x[i]);
    printf(")=%ld.\n",f[n]-1);
}
