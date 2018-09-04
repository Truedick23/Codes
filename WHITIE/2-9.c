#include<stdio.h>
#include<math.h>
int main()
{
    int a,b,c,d,rem;
    scanf("%d%d%d",&a,&b,&c);
    printf("%d.",d=a/b);
    rem=a-d*b;
    while(c--)
    {
        printf("%d",d=rem*10/b);
        rem=rem*10-d*b;
    }
    return 0;
}
