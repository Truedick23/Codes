#include<stdio.h>
#include<string.h>
int main()
{
    char c;
    int a,b,e,d;
    while(c=getchar()!=10)
    {
        if((c<='z'&&c>='a')||(c<='Z'&&c>='A'))
           a++;
        if(c==32)
            b++;
        if(c>='0'&&c<='9')
            e++;
        if(c==0)
            break;
        else
            d++;
    }
    printf("%d,%d,%d,%d",a,b,e,d);
    return 0;
}
