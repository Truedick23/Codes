/*�龳������    n��ˮ���������ϣ�����һ��Ҭ�Ӻ���Ϊƣ�Ͷ�˯���ˡ�
                ��һ��ˮ���������Ҭ�ӷ�Ϊn�ݣ����m��Ҭ�ӣ��������ߵĺ��ӣ�Ȼ���Լ�����һ�ݣ���ʣ�µ����º���һ�𣬼���˯��
                �ڶ���ˮ��������ͬ����Ҭ�ӷ�Ϊn�ݣ����m��Ҭ�ӣ�Ҳ���˺��ӣ��Լ�����һ�ݺ�˯��
                ������������
                �ڶ��죬��n��ˮ������������Ҭ�����˺ܶ࣬���ղ��������ʣ�µ�Ҭ�ӷֳ�n�ݣ�ǡ���ֶ��m�������˺���
        ���ڸ���������n��m(0<m<n<9)������ԭ�����Ҭ�������ж��ٸ�

        �������������µ���ʽ��
        y[i]=(ny[i+1]+m)/(n-1)  (i=1,2,����,n)
        Ϊ�������������ȷ����y[n+1]���Ƴ�y[n]����Ȼy[n+1]��ȡֵkֻ����k%(n-1)=n-m-1. �������ֵn-m+1���Ժ�n-1��ֵ
        */

#include<math.h>
#include<stdio.h>
void main()
{
    int i,m,n;
    double k,x,y[20];
    printf("Input n as the number of sailors(1<n<9): ");scanf("%d",&n);
    printf("Input m as the number of coconuts left every time(0<m<n): ");scanf("%d",&m);
    i=n+1;k=n-m-1;y[n+1]=k;
    while(i>1)
    {
        i--;
        y[i]=(y[i+1]*n+m)/(n-1);
        if(y[i]!=floor(y[i]))                           //�������������������ó�ֵ��ͷ����
        {
            k+=n-1;y[n+1]=k;i=n+1;
        }
    }
    x=n*y[i]+m;
    printf("The original number of coconuts: %8.0f.\n",x);
    for(i=1;i<=n;i++)
    {
        printf("N0.%2d sailor is faced with: ",i);
        printf("%8.0f=%d*%8.0f+%d; ",n*y[i]+m,n,y[i],m);
        printf("Hide %8.0f coconuts.\n",y[i]);
    }
    printf("In the end:");
    printf("%8.0f=%d*%8.0f+%d,",n*y[n+1]+m,n,y[n+1],m);
    printf("Every sailor get %8.0f.\n",y[n+1]);
}
