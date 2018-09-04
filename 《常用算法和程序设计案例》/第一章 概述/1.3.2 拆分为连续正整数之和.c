#include<stdio.h>
int main()
{
    long c,i,j,n,s;
    scanf("%ld",&n);
    c=0;
    for(i=1;i<=(n-1)/2;i++)                                     //枚举求和起始项
    {
        s=0;
        for(j=i;j<=(n+1)/2;j++)                                 //枚举求和类加项
        {
            s=s+j;
            if(s>=n)
            {if(s==n)
                {
                    c++;printf(" %d:%d+...+%d\n",c,i,j);        //统计并输出一个解
                }
                break;
            }
        }
                                          //输出解的个数
    } printf("%d\n",c);
    return 0;
}
