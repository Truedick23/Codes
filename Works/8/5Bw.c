#include<stdio.h>
int main()
{
    int a[100];
    int l,j,i,n,mark=0;
    int *p;
    for(i=0;i<100;i++)
    {
        a[i]=0;
    }
    scanf("%d%d",&l,&j);
    p=a;
    for(;p<(a+l);p++)
    {
        if(p==a+l-1)
        {
            p=a;
        }
        n=1;
        if(*p==0)
        {
            if(n==j)
            {
                *p++;
                mark++;
                p=a;
                n=1;
            }
            else n++;
        }

        if(mark==l-1) break;
    }

    printf("%d\n",*p);
    for(p=a;p<(a+l);p++)
    {
        printf("%d ",*p);
    }
}
