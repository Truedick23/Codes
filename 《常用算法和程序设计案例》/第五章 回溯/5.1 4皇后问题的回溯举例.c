#include<stdio.h>
#include<math.h>
int put(int k)
{
    int i,j,u,s,a[10];
    if(k<=4)
    {
        for(i=1;i<=4;i++)
        {
            for(u=0,j=1;j<=k-1;j++)
                if(a[k]==a[j]||abs(a[k]-a[j])==k-j)
                    u=1;
            if(u==0)
            {
                if(k==4)
                {
                    s++;printf(" ");
                    for(j=1;j<=4;j++)
                        printf("%d",a[j]);
                }
                else put(k+1);
            }
        }
    }
}
