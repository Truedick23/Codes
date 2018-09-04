#include<stdio.h>
#include<stdlib.h>
int main()
{
    int i,n,a[200000],b[10000],k=0;
    scanf("%d",&n);
    memset(b,0,sizeof(b));
    for(i=0;i<2*n;i++)
    {
        scanf("%d",&a[i]);
        if(b[a[i]]==1) break;
        else
        {
            b[a[i]]=1;
            k++;
        }
    }
    printf("%d",k);
}
