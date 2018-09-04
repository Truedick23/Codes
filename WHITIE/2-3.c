#include<stdio.h>
int main()
{
    int i,a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    for(i=10;i<100;i++)
    {
        if(i%3==a&&i%5==b&&i%7==c)  break;
    }
    if(i==100)  printf("No answer");
    else printf("%d",i);
}
