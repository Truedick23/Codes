#include<stdio.h>
#include<math.h>
#define PI 3.141
int f(int n,int k,int p)
{
    double ni;
    if(n==1)    return k;
    if(n==2)    return p;
    n--;
    ni=n/2;
    return f(n,k,p)+f(n-1,k,p)+sin(PI*ni);
}

int main()
{
    int n,f1,f2;
    while(scanf("%d%d%d",&f1,&f2,&n)==3)
        printf("%d\n",f(n,f1,f2)%1000000007);
    return 0;
}
