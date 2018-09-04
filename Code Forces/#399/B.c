#include<stdio.h>
#include<math.h>
int main()
{
    int n,l,r,a[10000],i,x,mid,length=1,t=0,m1,m2,m3,m4,temp,k=0;
    scanf("%d%d%d",&n,&l,&r);
    x=n;
    l--;r--;
    while(x!=1)
    {
        t++;
        x=x/2;
    }
    m1=n/pow(2,t);
    m2=n%2;
    m3=(n/(int)pow(2,t-1))%2;
    m4=(n/(int)pow(2,t-2))%2;
    for(i=1;i<=t;i++)
    {
        length+=pow(2,i);
    }
    mid=(length-1)/2;
    a[mid]=m2;
    for(i=0;i<=t;i++)
    {
        a[4*i]=m1;
        a[4*i+2]=m1;
        if(4*i+1!=mid)  a[4*i+1]=m3;
        if(4*i+3!=mid)  a[4*i+3]=m4;
    }
    for(i=0;i<length;i++)
        printf("%d ",a[i]);
    printf("\n");
    for(i=l;i<=r;i++)
        if(a[i]==1) k++;
    printf("%d",k);
    return 0;
}
