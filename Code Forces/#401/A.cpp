#include<stdio.h>
int main()
{
    int n,lp,p;
    scanf("%d%d",&n,&p);
    for(;n>0;n--)
    {
        if(n%2==0)
            {if(p==1) p=2;
            if(p==2) p=1;}
        else
            {if(p==1)    p=0;
            if(p==0)    p=1;}
    }
    printf("%d\n",p);
    return 0;
}
