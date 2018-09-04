#include<stdio.h>
int main()
{
    int t,m,n,i;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        scanf("%d",&n);
        for(m=0;m<n;m++)
        {
            m=2m+1;
        }
        printf("%d",m);
    }
    return 0;
}
