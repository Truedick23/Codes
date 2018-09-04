/*  ����n=2^k���˶�ԱҪ��������ѭ������
    ��Ҫ���һ����������Ҫ��ı����ճ̱�
    (1)ÿ��ѡ�ֱ���������n-1��ѡ�ָ���һ�Σ�
    (2)ÿ��ѡ��һ��ֻ�ܲ���һ�Σ�
    (3)ѭ������n-1���ڽ�����
    ����Ҫ�󽫱����ճ̱���Ƴ���n�к�n-1�е�һ�����ڱ��еĵ�i�У���j�д������i��ѡ���ڵ�j���������Ķ��֣�
    ����1<=i<=n��1<=j<=n-1.
    �����β��ԣ����Խ����е�ѡ�ֳַ����룬��n��ѡ�ֵı����ճ̱����ͨ��n/2��ѡ�ֵı����ճ̱���������*/

#include<iostream>
using namespace std;

#define MAX 100
int a[MAX][MAX];

//Դ��������ϽǶ�������(fromx,fromy)��������Ϊr
//Ŀ�귽������ϽǶ�������(tox,toy)��������Ϊr
void Copy(int tox,int toy,int fromx,int fromy,int r)
{
    for(int i=0;i<r;i++)
        for(int j=0;j<r;j++)
            a[tox+i][toy+j]=a[fromx+i][fromx+j];
}

void Table(int k)
{
    int i,r;
    int n=1<<k;
    for(i=0;i<n;i++)
        a[0][i]=i+1;
    for(r=1;r<n;r<<=1)
        for(i=0;i<n;i+=2*r)
        {
            Copy(r,r+i,0,i,r);
            Copy(r,i,0,r+i,r);
        }
}
