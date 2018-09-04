#include<stdio.h>
#include<math.h>
int main()
{
    int a[15]={1,5,6,10,11,15,17,26,34,44,54,57,66,78,81};
    int x,m,n,i,pos,t;
    for(t=0;t<15;t++)
        {printf("%d ",a[t]);}
    printf("\n");
    scanf("%d",&x);
    m=0;
    n=14;
    pos=15;
    if(a[0]==x)
        pos=0;
    if(a[14]==x)
        pos=14;
    else
    while(m<=n)
    {
        i=(m+n)/2;
        if(a[i]==x)
        {
            pos=i;
            break;
        }
        if(a[i]<x)
            m=i;
        if(a[i]>x)
            n=i;
        else
        {
            if(abs(m-n)==1)
            break;
        }

    }
    if(pos==15)
        printf("Not in this line");
    else printf("%d",pos);
    return 0;
}
