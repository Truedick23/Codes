#include<stdio.h>
#include<string.h>
int main()
{
    char a[100000],b[100000];
    int l1,l2,max;
    scanf("%s",a);
    scanf("%s",b);
    if(strcmp(a,b)==0)  max=-1;
    else max=(l1=strlen(a))>(l2=strlen(b))?l1:l2;
    printf("%d",max);
    return 0;
}
