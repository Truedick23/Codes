#include<stdio.h>
int main()
{
    int length,a[1000],b1[1000],b2[1000],i,t,b1min,b2min,p1,p2,or,r1=0,r2=0;
    char aa[1000],bb[1000];
    scanf("%d",%length);
    scanf("%s%s",aa,bb);
    for(i=0;i<length;i++)
    {
        a[i]=aa[i]-'0';
        b1[i]=b2[i]=bb[i]-'0';
    }
    for(i=0;i<length;i++)
    {
        b1min=b2min=9;
        for(t=0;t<length;t++)
        {
            if(b1[t]>=a[i]&&b1min>b1[t])
            {
                p1=t;
                b1min=b1[t];
            }
            if(b2[t]>a[i]&&b2min>b2[t])
            {
                p2=t;
                b2min=b2[t];
            }
        }
        swap(b1[i],b1[p1]);
        swap(b2[i],b2[p2]);
    }
    for(i=0;i<n;i++)
       {
           if(a[i]>=b1[i])  r1++;
           if(a[i]>=b2[i])  r2++;
       }
    printf("%d\n%d\n",r1,r2);
}
