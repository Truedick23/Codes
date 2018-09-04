#include<stdio.h>
#include<string.h>
void spa(char x[])
{
    char b[100];
    int i,t;
    for(i=0,t=0;i<strlen(x);i++,t=t+2)
    {
        b[t]=x[i];
        b[t+1]=' ';
    }
    printf("%s",b);
}

int main()
{
    char a[100];
    gets(a);
    spa(a);
    return 0;
}
