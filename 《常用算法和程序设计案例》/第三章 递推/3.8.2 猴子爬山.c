/*  һ���ú�����һ��Сɽ��n��̨����������һ����m�ֿ編��һ�������ɼ������Ӽ�������
    ������ɽ��n��̨���ж����ֲ�ͬ������

    ʵ���㷨��
    ����ɽt��̨�׵Ĳ�ͬ����Ϊf[t]����Ӽ��������m�������ֱ�Ϊx[1],x[2],...,x[m](Լ����С��������)
    ̽��f[t]�ĵ��ƹ�ϵ��
    ��t<x[1]ʱ��f[t]=0,f[x[1]]=1.
    ��x[1]<t<=x[2]ʱ����һ������: f[t]=f[t-x[1]].
    ��x[2]<t<=x[3]ʱ���ڶ�������: f[t]=f[t-x[1]]+f[t-x[2]].
    ��������
    һ��أ���x[k]<t<=x[k+1],k=1,2,����,m-1���е�k�����ƣ�
        f[t]=f[t-x[1]]+f[t-x[2]]+����+f[t-x[k]]
    ��t=x[m](m=1,2,3,....)ʱ�����ϵ�����f[t]�⣬��Ҫ����1����Ϊ��ʱ������һ����λ
    */

#include<stdio.h>
void main()
{
    int i,j,k,m,n,t,x[10];
    long f[200];
    printf("Input the number of stairs: ");scanf("%d",&n);
    printf("Input the number of methods: ");scanf("%d",&m);
    for(i=1;i<=m;i++)
    {
       printf("Input the No.%d method: ",i);
       scanf("%d",&x[i]);
    }
    for(i=1;i<=x[1]-1;i++)  f[i]=0;                 //��һ���������t<x[1]ʱ
    x[m+1]=n;f[x[1]]=1;                             //���ó�ʼ����
    for(k=1;k<=m;k++)
    for(t=x[k]+1;t<=x[k+1];t++)
    {
        f[t]=0;
        for(j=1;j<=k;j++)
            f[t]=f[t]+f[t-x[j]];                //����ʽ�������
        if(t==x[k+1])                           //t=x[k+1]ʱ����1
            f[t]=f[t]+1;
    }
    printf(" The number of methods in total is: ");
    printf("%d(%d",n,x[1]);
    for(i=2;i<=m;i++)
        printf(",%d",x[i]);
    printf(")=%ld.\n",f[n]-1);
}
