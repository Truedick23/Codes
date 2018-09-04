/*  定义计算A[i,j](1<=i<=j<=n)所需要的最少次数为m[i][j]，则原问题的最优解就是m[1][n]。
    当i<j时，若每个矩阵Ai的维数为p(i-1)*p(i)，则：
        m[i][j]=m[i][k]+m[k+1][j]+p(i-1)p(k)p(j);
    当i=j时，m[i][j]=0.        */

#include<iostream>
using namespace std;

#define NUM 51
int p[NUM];                 //用p数组记录矩阵的维数
int m[NUM][NUM];            //记录最优解
int s[NUM][NUM];            //用于记录最优断开位置
void MatrixChain(int n)
{
    for(int i=1;i<=n;i++)
        m[i][i]=0;
    for(int r=2;r<=n;r++).
        for(int i=1;i<=n-r=1;i++)
        {
            int j=i+r-1;
            m[i][j]=m[i+1][j]+p[i-1]*p[i]*p[j];
            s[i][j]=i;
            for(int k=i+1;k<j;k++)
            {
                int t=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
                if(t<m[i][j])   {m[i][j]=t;s[i][i]=k;}
            }
        }
}

void TraceBack(int i,int j)
{
    if(i==j)    printf("A%d",i);
    else
    {
        printf("(");
        TraceBack(i,s[i][j]);
        TraceBack(s[i][j]+1,j);
        printf(")");
    }
}
