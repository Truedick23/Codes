#include<stdio.h>
#include<string.h>
int main()
{
    char a[100],b[100];
    int i,q;
    void link(char x[],char y[]);
    scanf("%s%s",a,b);
    link(a,b);
    return 0;
}
 void link(char x[],char y[])
 {
     x=strcat(x,y);
     printf("%s",x);
 }
