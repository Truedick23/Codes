/*  LCS的最优子结构性质：
    设序列X={x1,x2,...,xm}和Y={y1,y2,...,yn}的一个最长公共子序列Z={z1,z2,..,zk}，则：
    (1)若xm=yn，则zk=xm=yn，且Zk-1是Xm-1和Yn-1的最长公共子序列；
    (2)若xm!=yn，且zk!=xm，则Z是X(m-1)和Y的最长公共子序列
    (3)若xm!=yn，且zk!=yn，则Z是X和Y(n-1)的最长公共子序列

    递归方法：
    (1)当xm=yn时，找出X(m-1)和Y(n-1)的最长公共子序列，然后在其尾部加上xm(=yn)可得两者最长公共子序列
    (2)当xm!=yn时，找出X(m-1)和Y的一个最长公共子序列及X和Y(n-1)的一个最长公共子序列，其中较长者为两者最长公共子序列
    */

#define NUM 100
int c[NUM][NUM];                 //用于记录最长公共子序列的长度
int b[NUM][NUM];                //此数组中b[i][j]用于记录从c[i][j]的值是由哪一个子问题的解得到的
void LCSLength(int m,int n,const char x[],char y[])
{
    int i,j;
    for(i=1;i<=m;i++)   c[i][0]=0;
    for(i=1;i<=n;i++)   c[0][i]=0;

    for(i=1;i<=m;i++)
    for(j=1;j<=n;j++)
    {
        if(x[i]==y[j])
        {
            c[i][j]=c[i-1][j-1]+1;
            b[i][j]=1;
        }
        else if(c[i-1][j]>=c[i][j-1])
        {
            c[i][j]=c[i-1][j];
            b[i][j]=2;
        }
        else
        {
            c[i][j]=c[i][j-1];
            b[i][j]=3;
        }
    }
}

void LCS(int i,int j,char x[])
{
    if(i==0||j==0)  return;
    if(b[i][j]==1)  {LCS(i-1,j-1,x);printf("%c",x[i]);}
    else if(b[i][j]==2) LCS(i-1,j,x);
    else LCS(i,j-1,x);
}
