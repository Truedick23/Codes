/*�����������壺����С�ڷ�ĸ���ҷ��ӷ�ĸ�޹�����*/

#include<stdio.h>
#include<math.h>
void main()
{
    int a,b,i,j,t,u;long m=0;
    double s;
    printf("Please input a and b, and the denominator is between [a,b]:");    //��������������
    scanf("%d%d",&a,&b);
    s=0;
    for(j=a;j<=b;j++)                                   //ö�ٷ�ĸ
    for(i=1;i<=j-1;i++)                                 //ö�ٷ���
    {
        for(t=0,u=2;u<=i;u++)                           //ö������
        if(j%u==0&&i%u==0)
        {
            t=1;break;                                  //���ӷ�ĸ�й�����,��ȥ
        }
        if(t==0)
        {
            m++;                                        //ͳ��������������
            s+=(double)i/j;                             //�����������ĺ�
        }
    }
    printf("There are %d in total.\n",m);
    printf("Sum=%.5f\n",s);
}
