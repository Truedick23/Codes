/*  设有n=2^k个运动员要进行网球循环赛。
    现要设计一个满足以下要求的比赛日程表：
    (1)每个选手必须与其他n-1个选手各赛一次；
    (2)每个选手一天只能参赛一次；
    (3)循环赛在n-1天内结束。
    按此要求将比赛日程表设计成有n行和n-1列的一个表。在表中的第i行，第j列处填入第i个选手在第j天所遇到的对手，
    其中1<=i<=n，1<=j<=n-1.
    按分治策略，可以将所有的选手分成两半，则n个选手的比赛日程表可以通过n/2个选手的比赛日程表来决定。*/

#include<iostream>
using namespace std;

#define MAX 100
int a[MAX][MAX];

//源方阵的左上角顶点坐标(fromx,fromy)，行列数为r
//目标方阵的左上角顶点坐标(tox,toy)，行列数为r
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
