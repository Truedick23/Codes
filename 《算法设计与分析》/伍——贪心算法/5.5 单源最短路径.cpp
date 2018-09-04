/* ������Ȩ����ͼG=(V,E)������ÿ���ߵ�Ȩ�ǷǸ�ʵ�������⣬������V�е�һ�����㣬��ΪԴ��
    ����Ҫ�����Դ��������������������·���ȣ������·�ĳ�����ָ·���ϸ���Ȩ֮�͡�
    Dijkstra�㷨�Ļ���˼���ǣ����ö��㼯��S�����ϵ���̰��ѡ��������������ϣ�һ���������� ����S���ҽ�����Դ���ö�������·��������֪��*/

#define NUM 100
#define maxint 10000
//����dist�����Դ��v��ÿ��������������·������
//����prev����ÿ���������������·���ϵ�ǰһ�����
void dijkstra(int n,int v,int dist[],int prev[],int c[][NUM])       //n�Ƕ��������v��Դ�㣬����ͼ���ڽӾ���Ϊc
{
    int i,j;
    bool s[NUM];
    for(i=1;i<=n;i++)                                       //��ʼ������
    {
        dist[i]=c[v][i];
        s[i]=false;
        if(dist[i]>maxint)      prev[i]=0;
        else prev[i]=v;
    }
    dist[v]=0;                                              //��ʼ��Դ���
    s[v]=true;
    for(i=1;i<=n;i++)                                       //���ඥ��
    {
        int tmp=maxint;
        int u=v;
        for(j=1;j<n;j++)
            if(!(s[j])&&(dist[j]<tmp))
            {
                u=j;
                tmp=dist[j];
            }
        s[u]=1;                                             //���u����s��
        for(j=1;j<=n;j++)                                   //���ý��u��������dist
            if(!(s[j])&&c[u][j]<maxint)
            {
                int newdist=dist[u]+c[u][j];                //newdistΪ��Դ�㵽�õ���������·��
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
