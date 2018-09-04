/*  如果0-1背包问题中的物品可以分割则称之为背包问题
    采用贪心算法，按性价比从高到低的顺序选取物品，剩下的空间装入剩余的物品的一部分*/

struct bag{
    int w;              //物品的重量
    int v;              //物品的价值
    double x;           //装入背包的量
    int index;
    double c;           //性价比
}a[1001];

bool cmp(bag a,bag b)
{
    if(a.c>b.c) return true;
    return false;
}

sort(a,a+n,cmp)

double knapsack(int n,bag a[],double c)
{
    double cleft=c;             //剩余容量
    int i=0;
    double b=0;                 //获得的价值
    while(i<n&&a[i].w<=cleft)
    {
        cleft-=a[i].w;
        b+=a[i].v;
        a[a[i].index].x=1.0;
        i++;
    }
    if(i<n)
    {
        a[a[i].index].x=1.0*cleft/a[i].w;
        b+=a[a[i].index].x*a[i].v;
    }
    return b;
}
