/*  ���Ƚ����ж��Ƿ��н⣬��x�ӿ�ʼ����ȡֵ����ֵ��fny(b)�Ƚϣ��������ʱ����ʱx��ֵ����x1��b����x2;
    Ȼ����λ�󾫣�ÿ��c��Ϊʮ��֮һ��ʹfny(x)��fny(x2)�Ƚϣ�
    ��������ţ�����һ��ͬ�ţ�������ֵ��x2=x,x1=x-c*/


#include<stdio.h>
#include<math.h>
double fny(double x)
{
    return 2*pow(x,2)*pow(sin(x),7)+pow(x,0.5)*cos(x)-exp(x)/5;
}
void main()
{
    int i,t=0;
    double a,b,x,x1,x2,c;
    printf("Input a and b:");
    scanf("%lf%lf",&a,&b);
    for(x=a;x<=b;x+=0.1)                //����ɨ�裬ȷ����ʼλ��
        if(fny(x)*fny(b)<=0)
    {
        x1=x;x2=b;t=1;break;
    }
    if(t==0)
    {
        printf("No Solution!");
        return;
    }
    c=0.01;
    for(i=2;i<=9;i++)                     //����
    {
        for(x=x1;x<=x2;x+=c)
            if(fny(x)*fny(x2)>0)           //�����Ϊͬ�ţ���Сѭ����Χ
        {
            x2=x;x1=x-c;break;              //������ֵ����ֵ
        }
        c=c/10;                             //��Сѭ��������
    }
    x=(x1+x2)/2;
    printf("x=%.8f",x);
}
