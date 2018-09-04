#include<stdio.h>
int main()
{
    int t,m,n,i,p,q,i1,i2,result;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        scanf("%d%d",&m,&n);
        q=1;
        p=1;
        for(i2=1;i2<=m;i2++)
        {
            q=q*i2;
        }
        for(i1=n-m+1;i1<=n;i1++)
        {
            p=p*i1;
        }
        result=p/q;
        printf("%d\n",result);
    }
    return 0;
}
