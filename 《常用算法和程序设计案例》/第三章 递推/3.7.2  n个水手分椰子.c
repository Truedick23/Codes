/*情境描述：    n个水手来到岛上，采了一堆椰子后，因为疲劳都睡着了。
                第一个水手醒来后把椰子分为n份，多出m个椰子，便给了身边的猴子，然后自己藏起一份，将剩下的重新合在一起，继续睡觉
                第二个水手醒来后，同样把椰子分为n份，多出m个椰子，也给了猴子，自己藏起一份后睡觉
                。。。。。。
                第二天，第n个水手醒来，发现椰子少了很多，心照不宣，便把剩下的椰子分成n份，恰好又多出m个，给了猴子
        对于给定的整数n、m(0<m<n<9)，试求原来这堆椰子至少有多少个

        根据题意有以下递推式：
        y[i]=(ny[i+1]+m)/(n-1)  (i=1,2,……,n)
        为精简试验次数，确保从y[n+1]递推出y[n]，显然y[n+1]的取值k只能是k%(n-1)=n-m-1. 因而赋初值n-m+1，以后按n-1增值
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
        if(y[i]!=floor(y[i]))                           //若非整数，则重新设置初值从头递推
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
