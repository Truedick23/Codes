#include<stdio.h>
int main()
{
    char a[10000],p;
    int n,u,r,d,l,r;
    scanf("%d%s",&n,a);
    for(p=a;p!='\0';p++)
    {
        if(*p=='U') u++;
        if(*p=='R') r++;
        if(*p=='D') d++;
        if(*p=='L') l++;
    }
    if(u!=d||r!=l)
    {
        r=0;
        printf("%d",r);
        return 0;
    }

}
