/*  ���0-1���������е���Ʒ���Էָ����֮Ϊ��������
    ����̰���㷨�����Լ۱ȴӸߵ��͵�˳��ѡȡ��Ʒ��ʣ�µĿռ�װ��ʣ�����Ʒ��һ����*/

struct bag{
    int w;              //��Ʒ������
    int v;              //��Ʒ�ļ�ֵ
    double x;           //װ�뱳������
    int index;
    double c;           //�Լ۱�
}a[1001];

bool cmp(bag a,bag b)
{
    if(a.c>b.c) return true;
    return false;
}

sort(a,a+n,cmp)

double knapsack(int n,bag a[],double c)
{
    double cleft=c;             //ʣ������
    int i=0;
    double b=0;                 //��õļ�ֵ
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
