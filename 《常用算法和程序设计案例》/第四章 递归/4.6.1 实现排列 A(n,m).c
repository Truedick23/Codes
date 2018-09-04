/*  案例要求：对指定的正整数m、n（约定1<m<=n），具体实现从n个不同元素中任取m个元素的每一排列*/

#include<stdio.h>
int m,n,a[30];long s=0;
void main()
{
    int p(int k);
    printf(" Input n(n<10): ");scanf("%d",&n);
    printf(" Input m(1<m<=n): ");scanf("%d",&m);
    p(1);
    printf("\n There are %ld results.\n",s);
}
int p(int k)
{
    int i,j,u;
    if(k<=m)
    {
        for(i=1;i<=n;i++)
        {
            a[k]=i;     //第k个数a[k]赋值i，并标识u=0
            for(u=0,j=1;j<=k-1;j++)
                if(a[k]==a[j])          //在前面出现相同的值，则标识u=1
                u=1;
            if(u==0)            //若与前面的数相比没有一个相等，则继续检查是否取够m个数
            {
                if(k==m)
                {
                    s++;printf(" ");            //若取够了m个数，则解的个数加一，输出此种情况
                    for(j=1;j<=m;j++)
                        printf("%d",a[j]);
                    if(s%10==0) printf("\n");
                }                               //此时并未跳出循环，而是回到i取i+1的时候，继续探索
                else p(k+1);                    //若没有取够，则继续探索a[k]的下一个数a[k+1]再次从(1~n)中取值
            }
        }
    }                                       //最后i等于n时候已经列举完了所有情形，跳出函数体
    return s;
}
