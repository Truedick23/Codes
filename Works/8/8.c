#include<stdio.h>
#define MAXN 10000
int main()
{
    char c[MAXN];
    int i=0,upp=0,low=0,sp=0,num=0,el=0;
    gets(c);
    for(;c[i]!='\0';i++)
    {
        if(c[i]>='a'&&c[i]<='z')    low++;
        else if(c[i]>='A'&&c[i]<='Z')    upp++;
        else if(c[i]==' ')       sp++;
        else if(c[i]>='1'&&c[i]<='9')    num++;
        else    el++;
    }
    printf("Lower character: %d\nUpper character: %d\nNumber: %d\nElse: %d\nSpace: %d\n",low,upp,num,el,sp);
    return 0;
}
