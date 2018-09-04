#include<stdio.h>
#include<string.h>
int main()
{
    int n=0;
    char a[10000];
    double aver,sum=0;
    while(scanf("%s",a)!=EOF)
    {
        sum+=strlen(a);
        n++;
    }
    aver=sum/n;
    printf("%f",aver);
}
