//��⣺ d<1+1/2-1/3+1/4+1/5-1/6+...��1/n
#include<stdio.h>
void main()
{
    long d,n,k;
    double s;
    printf("Input d:");
    scanf("%d",&d);
    printf(" %d<1+1/2-1/3+1/4+1/5-1/6+...��1/n have a solution: \n",d);
    n=1;s=0;
    while(1)
    {
        s=s+1.0/n+1.0/(n+1)-1.0/(n+2);
        if(s>d) break;                                             //��Ϊÿ����ķ��ű仯����ͬ�ģ�����3Ϊ���������з���
        n=n+3;
    }
    printf("n>=%ld\n",n+1);                       //�õ�һ�������
    k=1;s=0;
    while(k<=n)
    {
        if(k%3>0)   s=s+1.0/k;
        else s=s-1.0/k;
        if(s>d)
            printf(" n=%ld\n",k);
        k++;
    }
}