#include<stdio.h>
#include<string.h>
int main()
{
    int n,i;
    char str[10],enc[10];
    char c;
    while(scanf("%d%s",&n,str)!=EOF)
    {
            for(i=0;i<strlen(str);i++)
            {
                if(str[i]-n>='a'&&str[i]-n<='z')
                    enc[i]=str[i]-n;
                if(str[i]-n<'a')
                    enc[i]=str[i]-n+26;
                if(str[i]-n>'z')
                    enc[i]=str[i]-n-26;
            }
            printf("%s",enc);
    }
    return 0;
}
