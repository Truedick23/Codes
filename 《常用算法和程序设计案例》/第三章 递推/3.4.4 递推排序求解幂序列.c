/*  设x,y为非负整数，计算集合  M={2^x,3^y|x>=0,y>=0} 的元素由大到小排列的双幂序列第n项和前n项之和。
    之后探索x+y=i时各项与x+y=i-1时各项之间的递推规律：
    x+y=0时，元素为1
    x+y=1时，元素为2*1=2,3*1=3两项
    x+y=2时，元素有2*2=4,2*3=6,3*3=9三项
    x+y=3时，元素有2*4=8,2*6=12,2*9=18,3*3*3=27四项
    …………
    之后归纳出关系：x+y=i时，序列一共i+1项，其中前i项时x+y=i-1的所有i项分别乘以2所得，最后一项为x+y=i-1时的最后一项乘3所得
    (注意：只有小于n且大于0时才能赋值)*/

#include<stdio.h>
void main()
{
    int i,j,h,k,m,u,c[100];
    double d,n,t,f[1000];
    printf("Define n which every one is smaller than:");scanf("%lf",&n);
    printf("Input m which will be output:");scanf("%d",&m);
    k=1;t=1.0;i=1;
    c[0]=1;f[1]=1.0;
    while(1)
    {
        u=0;
        for(j=0;j<=i-1;j++)
        {
            h=c[i-1]+j;
            if(f[h]*2<n&&f[h]>0)            //为前i-1项赋值上一行各项乘2
            {
                k++;f[k]=f[h]*2;u=1;        //u为下一项是否是递推项的标识
                if(j==0)    c[i]=k;
            }
            else break;
        }
        t=t*3;
        if(t<n&&t>0)
        {
            k++;f[k]=t;                     //用t给每行最后一个数赋值
        }
        if(u==0)    break;
        i++;
    }
    for(i=1;i<k;i++)
        for(j=i+1;j<=k;j++)
        if(f[i]>f[j])                       //进行排序操作
    {
        d=f[i];f[i]=f[j];f[j]=d;
    }
    printf("There are %d that are smaller than %f\n",k,n);
    if(m<=k)
        printf("The %d small one is: %.0f\n",m,f[m]);
    else
        printf("m is too much big!");
}
