/*  ����һ����Ʒ����s={1,2,3,...,n}����Ʒi��������wi�����ֵ��vi��������������W�������������������W��
    ���޶���������W�ڣ����ѡ����Ʒ������ʹ����Ʒ���ܼ�ֵ��󣿣���xi��ʾ��Ʒiװ�뱳�������xi=0,1��
    ���������Ҫ�����У�
        Լ�����̣�(i=1)��(n)wixi<=W
        Ŀ�꺯����max(i=1)��(n)vixi
    ��ǰi����Ʒ��������Ϊj�ı����п�ת��Ϊ��
        (1)p(i+1,j)����װ����Ʒi��Ҳ����i�޷�װ��(0<=j<wi)���������������䡣
        (2)p(i+1,i-wi)+vi��װ����Ʒi(j>=wi)����������ֵvi���������������١�
        (3)�����һ����Ʒ����j>=wi����϶�װ�룬��ü�ֵvn����֮�޷�װ�룬���0  */

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
