/*  �����ж��Ƿ��н⣬x��a��ʼ��������0.1����ȡֵ���亯��ֵfny(x)��fny(b)���Ƚϣ�������������н⣬������⣻
    Ȼ�����ú�����Сֵmi��ͨ��fny(x)��mi��Ƚ��������Сֵ����xi��¼������
    Ȼ��������󾫣�����������Сʮ��֮һ���ı�ѭ����Χ*/

#include<stdio.h>
#include<math.h>
double fny(double x)
{
    return 2*pow(x,2)*pow(sin(x),7)+3*pow(x,0.5)*cos(x)-exp(x)/5;
}
void main()
{
    int k,t;
    double a,b,c,x,x1,y,mi;
    printf("Input a and b:");
    scanf("%lf,%lf",&a,&b);
    for(t=0,x=a;x<=b;x+=0.1)                         //������0.1����ɨ���Ƿ���ڽ�
        if(fny(x)*fny(b)<=0)
        {
            t=1;break;
        }
    if(t==0)
    {
        printf("No solution!\n");return;
    }
    c=0.1;k=1;mi=100.0;
    while(k<=8)                                       //����8����ѭ��
    {
        for(x=a;x<=b;x+=c)
        {
            y=fny(x);
            if(fabs(y)<mi)                            //�Ƚ���ȡ��Сֵmi
            {
                mi=fabs(y);x1=x;
            }
        }
        c=c/10;a=x1-5*c;b=x1+5*c;                      //��Сѭ��������
        k++;
    }
    printf("x=%.8f\n",x1);
}
