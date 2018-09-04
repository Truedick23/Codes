/*  ������n�������������и�������ɵ�����a1,a2,...,an��
    Ҫ����n������ѡȡ���ڵ�һ��ai,a(i+1),...aj(1<=i<=j<=n)��ʹ������������ĺͣ�
    ������������Ϊ������ʱ����������Ӷκ�Ϊ0��
    ��b[j]=max{k=i��j a[k]},i<=j<=n�����ݴ˶��壬��b[j-1]>0ʱ��b[j]=b[j-1]+a[j]������b[j]=a[j]��
    �ʿɵ�b[j]�Ķ�̬�滮�ݹ�ʽ��
            b[j]=max{b[j-1]+a[j],a[j]}��1<=j<=n      */

#define NUM 1001
int a[NUM];
int MaxSum(int n,int &besti,int &bestj)
{
    int sum=0;
    int b=0;
    int begin=0;
    for(int i=1;i<=n;i++)
    {
        if(b>0) b+=a[i];
        else {b=a[i];begin=i;}
        if(b>sum)
        {
            sum=b;
            besti=begin;
            bestj=i;
        }
    }
    return sum;
}
