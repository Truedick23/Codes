/*  һ�����Ʒ������е�ǰ�������£�1/2,3/5,4/7,6/10,8/13,9/15,����
    �ù۲����еĹ��ɹ����ǵ�i��ķ�ĸd�����c���ڹ�ϵd=c+i��������cΪ��֮ǰi-1���е����з��ӡ���ĸ������ͬ����С������
    �����n���ǰn���������
    ���ڵ��Ƶ���ƣ�ע�⵽c(i)>c(i-1)��ͬʱ��i>2ʱ����i�������ķ���c(i)��С�ڵ�i-1�������ķ�ĸd(i-1)��
    ������k������(c(i-1),d(i-1))ȡֵ��k�ֱ���d(1)~d(i-1)�Ƚϣ���������i��*/

#include<stdio.h>
void main()
{
    int n,i,k,t,j,kmax;
    long c[3001],d[3001];
    printf("Input integer n:");scanf("%d",&n);
    c[1]=1;d[1]=1;
    c[2]=3;d[2]=5;
    kmax=1;
    for(i=3;i<=n;i++)
    {
        for(k=c[i-1]+1;k<d[i-1];k++)
        {
            t=0;
            for(j=1;j<i-1;j++)
              if(k==d[j]) {t=1;break;}
            if(t==0)                                            //��k������(c(i-1),d(i-1))ȡֵ����������ͬ��k+1��Ƚϣ���û����ͬ�������i��
            {
                c[i]=k;d[i]=k+i;
                break;
            }
        }
        if(c[i]*d[kmax]>c[kmax]*d[i])
            kmax=i;
    }
    printf("The No.%d one is: %ld/%ld.\n",n,c[n],d[n]);
    printf("The maximum one is: ");
    for(i=1;i<=n;i++)
    {if(c[i]*d[kmax]==c[kmax]*d[i])
        printf("The No.%d: %ld/%ld.\n",i,c[i],d[i]);}               //����ж�����ֵ��һ��ȫ�����
}
