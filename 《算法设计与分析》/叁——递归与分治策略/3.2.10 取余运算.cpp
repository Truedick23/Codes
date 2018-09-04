/*  ȡ����������a,p,k����a^p%k��ֵ��
    ģ�����������������
    (a*b)%n=(a%n*b%n)%n
    a^b%n=((a%n)^b)%n

    ��˵õ����µ��ƹ�ʽ��
    a^p%k=  1. a%k,     p=1
            2. (a*a^(p-1)%k)%k,     p������
            3.  ((a*a)%k)^(p/2)%k,  p��ż��    */

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
