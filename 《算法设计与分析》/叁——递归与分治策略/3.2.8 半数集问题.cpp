/*  给定一个自然数n，由n开始可以依次产生半数集set(n)中的数如下。
    (1) n∈set(n);
    (2)在n的左边加上一个自然数，但该自然数不能超过最近添加的数的一半；
    (3)按此规则进行处理，直到不能再添加自然数为止。

    记忆式搜索算法：        */

#include<iostream>
using namespace std;

int a[1001];
int comp(int n)
{
    int ans=1;
    if(a[n]>0)  return a[n];
    for(int i=1;i<=n/2;i++)
        ans+=comp(i);
    a[n]=ans;
    return ans;
}

int n;
while(cin>>n)
{
    memset(a,0,sizeof(a));
    a[1]=1;
    cout<<comp(n)<<endl;
}


