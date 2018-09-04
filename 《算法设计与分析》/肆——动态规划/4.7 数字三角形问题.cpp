/*  数字三角形问题：试设计一个算法，计算出从三角形的顶至底的一条路径，使该路径经过的数字总和最大。
    自下而上逐层决策的状态转移方程：
        tri[i][j]=tri[i][j]+max{tri[i+1][j],tri[i+1][j+1]}，其中i=n-1,n-3,...,0，0<=j<=i    */

#define NUM 100
int tri[NUM][NUM];
int triangle(int n)
{
    int i,j;
    for(i=n-1;i>=0;i--)
    for(j=0;j<=i;j++)w
    {
        if(tri[i+1][j]>tri[i+1][j+1])
            tri[i][j]+=tri[i+1][j];
        else tri[i][j]+=tri[i+1][j+1];
    }
    return tri[0][0];
}
