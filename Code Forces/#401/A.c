#include<stdio.h>
int main()
{
    int n,lp,p,l=1,k;
    scanf("%d%d",&n,&p);
    n%=6;
    for(;n>0;n--)
    {
        if(n%2==0)  k=1;
        else k=0;
        if(k==1)
        {
            if(p==1)     {p=2;}
            else if(p==2)     {p=1;}
        }
        else
        {
            if(p==1)    {p=0;}
            else if(p==0)    {p=1;}
        }
    }
    printf("%d\n",p);
    return 0;
}
