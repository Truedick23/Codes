/*  ����m(m>1)λ����������
    ��1������Ϊ����    ��2���Ӹ�λ��ʼ��ȥ��1λ��Ϊm-1λ������ȥ��2λ��������ȥ��m-1λ��Ϊ1λ������
    */

#include<stdio.h>
#include<math.h>
void main()
{
    int i,m;
    long c,d,e,f,k,s,t;
    int p(long f);
    printf("Input m:(m>1): ");scanf("%d",&m);
    for(c=1,i=1;i<=m-1;i++)
        c=c*10;                                             //ȷ��mλ������ʼ��c
    s=0;
    for(f=c+1;f<=10*c-1;f+=2)
    {
        if(p(f)==0||!(f%10==3||f%10==7))    continue;       //���о���ĳ�����������������λ������3��7������������λ��Ϊ3��7���������ų�
        for(t=1,d=f/10,i=1;i<=m-2;i++)
        {
            if(d%10==0) t=0;                                //������λ�г���0��Ӧ���ų�
            d=d/10;
        }
        if(t==0)    continue;
        for(t=1,k=10,i=1;i<=m-2;i++)
        {
            k=k*10;t=t*p(f%k);                               //�𲽼���ȥ����λ���ǲ��ǻ�������
        }
        if(t==0)    continue;                                //t=0ʱ˵�����ڷ�����
        s++;e=f;
    }
    printf("   There are %ld integer(s) that are super prime.\n",s,m);
    printf("    The maximum one among which is %ld.\n",e);
}
#include<math.h>
int p(long k)
{
    int j,h,z;
    z=0;
    if(k==2)    z=1;
    if(k>=3&&k%2==1)
    {
        for(h=0,j=3;j<=sqrt(k);j+=2)
            if(k%j==0)  {h=1;break;}
        if(h==0)    z=1;
    }
    return z;
}
