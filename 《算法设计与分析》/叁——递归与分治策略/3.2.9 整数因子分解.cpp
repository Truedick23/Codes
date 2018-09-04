/*  大于1的正整数n可以分解为：n=x1*x2*...*xm
    对于给定的正整不同的分解式数n，编程计算n共有多少种不同的分解式。

    对n的每个因子递归搜索：        */

#include<iostream>
using namespace std;
int total;
void solve(int n)
{
    if(n==1)    total++;
    else for(int i=2;i<=n;i++)
        if(n%i==0)  solve(n/i);
}

int n;
while(scanf("%d",&n)!=EOF)
{
    total=0;
    solve(n);
    printf("%d\n",total);
}
