#include<stdio.h>
#include<math.h>
void main()
{
    int i,j,k,i2,j2,k2,n,s,t,w,z,max,p[9000],q[1500];
    long m;
    printf("Input n:");
    scanf("%d",&n);
    for(i=3;i<=3*n;i+=2)
    {
        t=1;z=(int)sqrt(i);
        for(j=3;j<=z;j+=2)
            if(i%j==0)  {t=0;break;}
        if(t==1)    p[i]=1;                     //奇数i为素数时标记为1
    }
    w=0;
    for(i=3;i<=n;i=i+2)
        if(p[i]==1)
    {
        w++;q[w]=i;                             //共w个不大于n的奇素数赋给q数组
    }
    m=0;max=0;
    for(i=1;i<=w-2;i++)
    for(j=i+1;j<=w-1;j++)                       //注意此处i,j,k范围的设置，确保三数不相等
    for(k=j+1;k<=w;k++)
    {
        s=q[i]+q[j]+q[k];                       //统计三个素数之和s
        if(p[s]==1)
        {
            m++;                                //统计全素组个数
            if(s>max)                           //比较并记录最大全素组
            {
                max=s;i2=q[i];j2=q[j];k2=q[k];
            }
        }
    }
    printf("There are %ld in total\n",m);
    if(m>0)
    {
        printf("The maximum one is: %d+%d+%d=%ld\n",i2,j2,k2,max);
    }
}
