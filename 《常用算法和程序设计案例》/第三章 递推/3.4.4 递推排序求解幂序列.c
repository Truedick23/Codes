/*  ��x,yΪ�Ǹ����������㼯��  M={2^x,3^y|x>=0,y>=0} ��Ԫ���ɴ�С���е�˫�����е�n���ǰn��֮�͡�
    ֮��̽��x+y=iʱ������x+y=i-1ʱ����֮��ĵ��ƹ��ɣ�
    x+y=0ʱ��Ԫ��Ϊ1
    x+y=1ʱ��Ԫ��Ϊ2*1=2,3*1=3����
    x+y=2ʱ��Ԫ����2*2=4,2*3=6,3*3=9����
    x+y=3ʱ��Ԫ����2*4=8,2*6=12,2*9=18,3*3*3=27����
    ��������
    ֮����ɳ���ϵ��x+y=iʱ������һ��i+1�����ǰi��ʱx+y=i-1������i��ֱ����2���ã����һ��Ϊx+y=i-1ʱ�����һ���3����
    (ע�⣺ֻ��С��n�Ҵ���0ʱ���ܸ�ֵ)*/

#include<stdio.h>
void main()
{
    int i,j,h,k,m,u,c[100];
    double d,n,t,f[1000];
    printf("Define n which every one is smaller than:");scanf("%lf",&n);
    printf("Input m which will be output:");scanf("%d",&m);
    k=1;t=1.0;i=1;
    c[0]=1;f[1]=1.0;
    while(1)
    {
        u=0;
        for(j=0;j<=i-1;j++)
        {
            h=c[i-1]+j;
            if(f[h]*2<n&&f[h]>0)            //Ϊǰi-1�ֵ��һ�и����2
            {
                k++;f[k]=f[h]*2;u=1;        //uΪ��һ���Ƿ��ǵ�����ı�ʶ
                if(j==0)    c[i]=k;
            }
            else break;
        }
        t=t*3;
        if(t<n&&t>0)
        {
            k++;f[k]=t;                     //��t��ÿ�����һ������ֵ
        }
        if(u==0)    break;
        i++;
    }
    for(i=1;i<k;i++)
        for(j=i+1;j<=k;j++)
        if(f[i]>f[j])                       //�����������
    {
        d=f[i];f[i]=f[j];f[j]=d;
    }
    printf("There are %d that are smaller than %f\n",k,n);
    if(m<=k)
        printf("The %d small one is: %.0f\n",m,f[m]);
    else
        printf("m is too much big!");
}
