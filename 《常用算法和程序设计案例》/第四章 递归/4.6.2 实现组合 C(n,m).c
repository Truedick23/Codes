/*  ע�⵽��������Ԫ�ص�˳���޹أ�Լ������е����Ԫ�ذ���������
    ���������������˳���е�Լ���������ڡ�==����Ϊ���ڵ��ڡ�>=����Ȼ���������˺ܶ���Ч������Ч�ʵ͡�
    */

#include<stdio.h>
int m,n,a[100];
long s=0;
void main()
{
    int c(int k);
    printf(" Input n(n<10):");scanf("%d",&n);
    printf(" Input m(1<m<=n):");scanf("%d",&m);
    c(1);
    printf("\n C(%d,%d)=%ld \n",n,m,s);
}
int c(int k)
{
    int i,j;
    if(k<=m)
    {
        a[0]=0;
        for(i=a[k-1]+1;i<=n+k-m;i++)
        {
            a[k]=i;                 //�Ե�k������ֵi����֤a[k]��a[k-1]�󣬶���С����������
            if(k==m)                //�����Ѿ�ȡ������ʵʩ���
            {
                s++;printf(" ");
                for(j=1;j<=m;j++)
                    printf("%d",a[j]);
                if(s%10==0) printf("\n");
            }
            else
                c(k+1);         //������û��ȡ�������������ȡֵ
        }
    }
    return s;
}
