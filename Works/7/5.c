#include<stdio.h>
#include<string.h>
int main()
{
    char a[100];
    int len;
    gets(a);
    len=strlen(a);
    void tran(char x[],int n);
    tran(a,len);
    return 0;
}

void tran(char x[],int n)
{
    char y[100];
    int i;
    for(i=0;i<n;i++)
    {
       y[i]=x[n-1-i];
    }
    puts(y);
}
