/* 给定带权有向图G=(V,E)，其中每条边的权是非负实数。另外，还给定V中的一个顶点，称为源。
    现在要计算从源到所有其他各顶点的最短路长度，这里的路的长度是指路边上各边权之和。
    Dijkstra算法的基本思想是，设置顶点集合S并不断地做贪心选择来扩充这个集合，一个顶点属于 集合S当且仅当从源到该顶点的最短路径长度已知。*/

#define NUM 100
#define maxint 10000
//数组dist保存从源点v到每个顶点的最短特殊路径长度
//数组prev保存每个顶点在最短特殊路径上的前一个结点
void dijkstra(int n,int v,int dist[],int prev[],int c[][NUM])       //n是顶点个数，v是源点，有向图的邻接矩阵为c
{
    int i,j;
    bool s[NUM];
    for(i=1;i<=n;i++)                                       //初始化数组
    {
        dist[i]=c[v][i];
        s[i]=false;
        if(dist[i]>maxint)      prev[i]=0;
        else prev[i]=v;
    }
    dist[v]=0;                                              //初始化源结点
    s[v]=true;
    for(i=1;i<=n;i++)                                       //其余顶点
    {
        int tmp=maxint;
        int u=v;
        for(j=1;j<n;j++)
            if(!(s[j])&&(dist[j]<tmp))
            {
                u=j;
                tmp=dist[j];
            }
        s[u]=1;                                             //结点u加入s中
        for(j=1;j<=n;j++)                                   //利用结点u更新数组dist
            if(!(s[j])&&c[u][j]<maxint)
            {
                int newdist=dist[u]+c[u][j];                //newdist为从源点到该点的最短特殊路径
                if(newdist<dist[j])
                {
                    dist[j]=newdist;
                    prev[j]=u;
                }
            }
    }
}

void traceback(int v,int i,int prev[])
{
    cout<<i<<"--";
    i=prev[i];
    if(i!=v)    traceback(v,i,prev);
    if(i==v)    cout<<1<<endl;
}
