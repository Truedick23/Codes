#include<stdio.h>
#include<math.h>
int main()
{
    int j,k,m,n,a[40000];
    long g,t;double s;
    scanf("%d",&n);
    s=0;
    for(k=2;k<=n;k++)
        s+=log10(k);                            //�����ۼ�ȷ��λ��
    m=(int)s+1;
    for(k=1;k<=m;k++)   a[k]=0;
    a[1]=1;g=0;
    for(k=2;k<=n;k++)
    for(j=1;j<=m;j++)
    {
        t=a[j]*k+g;                             //��jλ��k��gΪ��λ��
        a[j]=t%10;                              //�˻�t�ĸ�λ���ִ��ڱ�Ԫ��
        g=t/10;                                 //�˻�t��ʮλ����������Ϊ��λ��
    }
    j=1;
    while(a[j]==0)  j++;
    printf("!%d have %d zero in total\n",n,j-1);
    return 0;
}
