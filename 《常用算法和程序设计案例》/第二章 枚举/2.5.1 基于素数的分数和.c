/*s(n)=1/3-3/5-5/7+7/9+9/11-11/13+...±2n-1/2n+1 （分子分母只有一个素数取+，没有素数或都是素数取-）
    （1）求s(2016)     (2)设1<=n<=2016，求n为多大时s(n)最大     （3）设1<=n<=2016，求n为多大时，s(n)最接近0*/

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
        if(t==0)    a[k]=1;             //标记第k个奇数2k-1为素数
    }
    s=0;smax=0;mi=10;
    for(k=1;k<=n;k++)
    {
        if(a[k]+a[k+1]==1)              //判断a[k]和a[k+1]中有一个素数
            s+=(double)(2*k-1)/(2*k+1); //实施加
        else
            s-=(double)(2*k-1)/(2*k+1);         //否则实施减
        if(s>smax) {smax=s;k1=k;}                       //比较求最大值smax
        if(fabs(s)<mi) {mi=fabs(s);k2=k;s2=s; }         //绝对是比较求最接近0点
    }
    printf("s(%d)=%.5f\n",n,s);
    printf("When k=%d, the maximum of s is: %.5f.\n",k1,smax);
    printf("When k=%d, the closest to zero %.5f.\n",k2,s2);
}
