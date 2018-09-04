#include<stdio.h>
#include<string.h>
int main()
{
    char a[100];
    char b[100];
    int l,i,k=0;
    scanf("%s",a);
    l=strlen(a);
    for(i=0;i<l;i++)
    {
        if(a[i]>='a'&&a[i]<='z')
        {
             b[i]=219-a[i];
        }
        else if(a[i]>='A'&&a[i]<='Z')
        {
            b[i]=155-a[i];
        }
        else k=1;
    }
    if(k)   printf("There is a typo in your string");
    else
    {
        for(i=0;i<l;i++)
        {
            printf("%c",b[i]);
        }
    }
    return 0;
}
