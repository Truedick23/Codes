/*  定义m(m>1)位超级素数：
    （1）本身为素数    （2）从高位开始，去掉1位后为m-1位素数；去掉2位。。。。去掉m-1位后为1位素数。
    */

#include<stdio.h>
#include<math.h>
void main()
{
    int i,m;
    long c,d,e,f,k,s,t;
    int p(long f);
    printf("Input m:(m>1): ");scanf("%d",&m);
    for(c=1,i=1;i<=m-1;i++)
        c=c*10;                                             //确定m位数的起始数c
    s=0;
    for(f=c+1;f<=10*c-1;f+=2)
    {
        if(p(f)==0||!(f%10==3||f%10==7))    continue;       //若列举中某数本身不是素数，或个位数不是3或7（超级素数个位必为3或7）则首先排除
        for(t=1,d=f/10,i=1;i<=m-2;i++)
        {
            if(d%10==0) t=0;                                //若其他位中出现0，应予排除
            d=d/10;
        }
        if(t==0)    continue;
        for(t=1,k=10,i=1;i<=m-2;i++)
        {
            k=k*10;t=t*p(f%k);                               //逐步检验去掉各位后是不是还是素数
        }
        if(t==0)    continue;                                //t=0时说明存在非素数
        s++;e=f;
    }
    printf("   There are %ld integer(s) that are super prime.\n",s,m);
    printf("    The maximum one among which is %ld.\n",e);
}
#include<math.h>
int p(long k)
{
    int j,h,z;
    z=0;
    if(k==2)    z=1;
    if(k>=3&&k%2==1)
    {
        for(h=0,j=3;j<=sqrt(k);j+=2)
            if(k%j==0)  {h=1;break;}
        if(h==0)    z=1;
    }
    return z;
}
