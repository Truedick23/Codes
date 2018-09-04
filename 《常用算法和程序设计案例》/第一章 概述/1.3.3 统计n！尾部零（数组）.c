#include<stdio.h>
#include<math.h>
int main()
{
    int j,k,m,n,a[40000];
    long g,t;double s;
    scanf("%d",&n);
    s=0;
    for(k=2;k<=n;k++)
        s+=log10(k);                            //对数累加确定位数
    m=(int)s+1;
    for(k=1;k<=m;k++)   a[k]=0;
    a[1]=1;g=0;
    for(k=2;k<=n;k++)
    for(j=1;j<=m;j++)
    {
        t=a[j]*k+g;                             //第j位乘k，g为进位数
        a[j]=t%10;                              //乘积t的个位数字存于本元素
        g=t/10;                                 //乘积t的十位以上数字作为进位数
    }
    j=1;
    while(a[j]==0)  j++;
    printf("!%d have %d zero in total\n",n,j-1);
    return 0;
}
