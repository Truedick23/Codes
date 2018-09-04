#include<stdio.h>
#include<string.h>
void cut(char c[],int m,int n)
{
    char *p,d[100],i=0;
    for(p=c+m;i<=n-m;p++,i++)
    {
        d[i]=*p;
    }
    printf("\n%s\n%s\n",c,d);
}

int main()
{
    char c[100];
    int m,n;
    scanf("%s%d",c,&m);
    n=strlen(c);
    cut(c,m,n);
    return 0;
}
