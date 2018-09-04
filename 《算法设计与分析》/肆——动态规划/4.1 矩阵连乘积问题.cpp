/*  �������A[i,j](1<=i<=j<=n)����Ҫ�����ٴ���Ϊm[i][j]����ԭ��������Ž����m[1][n]��
    ��i<jʱ����ÿ������Ai��ά��Ϊp(i-1)*p(i)����
        m[i][j]=m[i][k]+m[k+1][j]+p(i-1)p(k)p(j);
    ��i=jʱ��m[i][j]=0.        */

#include<iostream>
using namespace std;

#define NUM 51
int p[NUM];                 //��p�����¼�����ά��
int m[NUM][NUM];            //��¼���Ž�
int s[NUM][NUM];            //���ڼ�¼���ŶϿ�λ��
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
