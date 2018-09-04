/*  取三个正整数a,p,k，求a^p%k的值。
    模运算有如下运算规则：
    (a*b)%n=(a%n*b%n)%n
    a^b%n=((a%n)^b)%n

    因此得到以下递推公式：
    a^p%k=  1. a%k,     p=1
            2. (a*a^(p-1)%k)%k,     p是奇数
            3.  ((a*a)%k)^(p/2)%k,  p是偶数    */

#include<iostream>
using namespace std;

int mod(int a,int p,int k)
{
    if(p==1)    return a%k;
    if(p%2) return mod(a%k,p-1,k)*a*k;
    else return mod((a*a)%k,p/2,k);
}

unsigned a,p,k;
while(scanf("%u%u%u",&a,&p,&k)!=EOF)
    printf("%d\n",mod(a,p,k));
