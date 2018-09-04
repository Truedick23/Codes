#include<stdio.h>
#include<string.h>
int main()
{
    int m,n,t=0;
    char a[20];
    char b[20];
    char c[30];
    scanf("%s%s",a,b);
    m=strlen(a)-1;
    n=srtlen(b)-1;
    while(m>=0&&n>=0)
    {
        c[t++]=a[m]-'0'+b[n]-'0';
        m--;n--;
    }
    while(m>=0)
    {
        c[t++]=a[m]-'0';
        m--;
    }
    while(n>=0)
    {
        c[t++]=a[n]-'0';
        n--;
    }
    for

}
