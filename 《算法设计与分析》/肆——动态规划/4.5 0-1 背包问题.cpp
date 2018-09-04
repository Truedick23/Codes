/*  给定一个物品集合s={1,2,3,...,n}，物品i的重量是wi，其价值是vi，背包的容量是W，即最大载重量不超过W。
    在限定的总重量W内，如何选择物品，才能使得物品的总价值最大？，用xi表示物品i装入背包的情况xi=0,1。
    根据问题的要求，则有：
        约束方程：(i=1)Σ(n)wixi<=W
        目标函数：max(i=1)Σ(n)vixi
    将前i个物品放入容量为j的背包中可转化为：
        (1)p(i+1,j)：不装入物品i，也可能i无法装入(0<=j<wi)，背包的容量不变。
        (2)p(i+1,i-wi)+vi：装入物品i(j>=wi)，则新增价值vi，但背包容量减少。
        (3)对最后一个物品，若j>=wi，则肯定装入，获得价值vn，反之无法装入，获得0  */

#define NUM 50
#define CAP 1500
int w[NUM];
int v[NUM];
int p[NUM][CAP];
void knapsack(int c,int n)
{
    int jMax=min(w[n]-1,c);
    for(int j=0;j<=jMax;j++)
        p[n][j]=0;
    for(int j=w[n];j<=c;j++)
        p[n][j]=v[n];
    for(int i=n-1;i>1;i--)
    {
        jMax=min(w[i]-1,c);
        for(int j=0;j<jMax;j++)
            p[i][j]=p[i+1][j];
        for(int j=w[i];j<=c;j++)
            p[i][j]=max(p[i+1][j],p[i+1][j-w[i]]+v[i]);
    }
    p[1][c]=p[2][c];
    if(c>=w[1])
        p[1][c]=max(p[1][c],p[2][c-w[1]]+v[1]);
}
