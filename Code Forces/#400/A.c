#include<stdio.h>
#include<string.h>
int main()
{
    char a1[20],b1[20],a[20],b[20];
    int n,i;
    scanf("%s%s",&a1,&b1);
    scanf("%d",&n);
    printf("%s %s\n",a1,b1);
    for(i=0;i<n;i++)
    {
        scanf("%s%s",&a,&b);
        if(strcmp(a,a1)==0) strcpy(a1,b);
        else strcpy(b1,b);
        printf("%s %s\n",a1,b1);
    }
    return 0;
}
