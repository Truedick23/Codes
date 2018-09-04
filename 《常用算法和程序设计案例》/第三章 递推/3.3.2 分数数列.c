/*  一个递推分数数列的前六项如下：1/2,3/5,4/7,6/10,8/13,9/15,……
    该观察数列的构成规律是第i项的分母d与分子c存在关系d=c+i，而分子c为与之前i-1项中的所有分子、分母均不相同的最小正整数
    试求第n项和前n项中最大项
    对于递推的设计：注意到c(i)>c(i-1)，同时当i>2时，第i个分数的分子c(i)总小于第i-1个分数的分母d(i-1)，
    所以让k在区间(c(i-1),d(i-1))取值，k分别与d(1)~d(i-1)比较，来产生第i项*/

#include<stdio.h>
void main()
{
    int n,i,k,t,j,kmax;
    long c[3001],d[3001];
    printf("Input integer n:");scanf("%d",&n);
    c[1]=1;d[1]=1;
    c[2]=3;d[2]=5;
    kmax=1;
    for(i=3;i<=n;i++)
    {
        for(k=c[i-1]+1;k<d[i-1];k++)
        {
            t=0;
            for(j=1;j<i-1;j++)
              if(k==d[j]) {t=1;break;}
            if(t==0)                                            //置k在区间(c(i-1),d(i-1))取值，若存在相同则k+1后比较；若没有相同则产生第i项
            {
                c[i]=k;d[i]=k+i;
                break;
            }
        }
        if(c[i]*d[kmax]>c[kmax]*d[i])
            kmax=i;
    }
    printf("The No.%d one is: %ld/%ld.\n",n,c[n],d[n]);
    printf("The maximum one is: ");
    for(i=1;i<=n;i++)
    {if(c[i]*d[kmax]==c[kmax]*d[i])
        printf("The No.%d: %ld/%ld.\n",i,c[i],d[i]);}               //如果有多个最大值则一次全部输出
}
