#include<stdio.h>
#include<math.h>
int f1,f2;
int f(int n)
{
    if(n==1)    return f1;
    else if(n==2)    return f2;
    else return f(n-1)+f(n-2)+sin(3.1415926*(n-1)/2);
}

int mod(int a,int b)
{
    return a%b;
}

int main()
{
    int n,f1,f2;
    scanf("%d%d%d",&f1,&f2,&n);
    printf("%d\n",f(n)%1000000007);
    return 0;
}
