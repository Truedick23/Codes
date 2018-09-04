#include<stdio.h>
void swap(int *a,int *b)
{
    int t;
    t=*a;
    *a=*b;
    *b=t;
}

int main()
{
    int length,a[1000],b1[1000],b2[1000],i,t;
    int b1min,b2min,p1,p2,or,r1=0,r2=0;
    char aa[1000],bb[1000];
    scanf("%d",&length);
    scanf("%s%s",aa,bb);
    for(i=0;i<length;i++)
    {
        a[i]=aa[i]-'0';
        b1[i]=bb[i]-'0';
        b2[i]=bb[i]-'0';
    }
    for(i=0;i<length-1;i++)
        for(t=i+1;t<length;t++)
            if(a[i]>a[t])   swap(a+i,a+t);
    for(i=0;i<length;i++)
    {
        b1min=9;
        b2min=9;
        p1=i;
        p2=i;
        for(t=i;t<length;t++)
        {
            if(b1[t]>=a[i]&&b1min>=b1[t])
            {
                p1=t;
                b1min=b1[t];
            }
            if(b2[t]>a[i]&&b2min>=b2[t])
            {
                p2=t;
                b2min=b2[t];
            }
        }
        if(i!=p1)    swap(b1+i,b1+p1);
        if(i!=p2)   swap(b2+i,b2+p2);
    }
    for(i=0;i<length;i++)
       {
           if(a[i]>b1[i])  r1++;
           if(a[i]<b2[i])  r2++;
       }
    printf("%d\n%d\n",r1,r2);
    return 0;
}
