/*  ����1��������n���Էֽ�Ϊ��n=x1*x2*...*xm
    ���ڸ�����������ͬ�ķֽ�ʽ��n����̼���n���ж����ֲ�ͬ�ķֽ�ʽ��

    ��n��ÿ�����ӵݹ�������        */

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
