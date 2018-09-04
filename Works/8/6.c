#include<stdio.h>
int lenth(char c[])
{
    char *p;
    p=c;
    while(*p!='\0') p++;
    return p-c;
}
int main()
{
    char c[100];
    while(gets(c)!=NULL)
    {
        printf("%d\N",lenth(c));
    }
    return 0;
}
