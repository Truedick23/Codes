/*s(n)=1/3-3/5-5/7+7/9+9/11-11/13+...��2n-1/2n+1 �����ӷ�ĸֻ��һ������ȡ+��û��������������ȡ-��
    ��1����s(2016)     (2)��1<=n<=2016����nΪ���ʱs(n)���     ��3����1<=n<=2016����nΪ���ʱ��s(n)��ӽ�0*/

#include<stdio.h>
#include<math.h>
void main()
{
    int t,j,n,k,k1,k2,a[3000];
    double s,s2,smax,mi;
    printf("Input an integer:");
    scanf("%d",&n);
    for(k=1;k<=n+1;k++) a[k]=0;
    for(k=2;k<=n+1;k++)
    {
        for(t=0,j=3;j<=sqrt(2*k-1);j+=2)
            if((2*k-1)%j==0)
            {
                t=1;break;
            }
        if(t==0)    a[k]=1;             //��ǵ�k������2k-1Ϊ����
    }
    s=0;smax=0;mi=10;
    for(k=1;k<=n;k++)
    {
        if(a[k]+a[k+1]==1)              //�ж�a[k]��a[k+1]����һ������
            s+=(double)(2*k-1)/(2*k+1); //ʵʩ��
        else
            s-=(double)(2*k-1)/(2*k+1);         //����ʵʩ��
        if(s>smax) {smax=s;k1=k;}                       //�Ƚ������ֵsmax
        if(fabs(s)<mi) {mi=fabs(s);k2=k;s2=s; }         //�����ǱȽ�����ӽ�0��
    }
    printf("s(%d)=%.5f\n",n,s);
    printf("When k=%d, the maximum of s is: %.5f.\n",k1,smax);
    printf("When k=%d, the closest to zero %.5f.\n",k2,s2);
}
