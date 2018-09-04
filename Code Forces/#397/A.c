#include<stdio.h>
int main()
{
    int l,i;
    char h[4],w[10];
    scanf("%d",&l);
    scanf("%s",h);
    for(i=0;i<l;i++)
        scanf("%s",w);
    if(l%2==0)   printf("home\n");
    else    printf("contest\n");
}
