#include<stdio.h>
#include<string.h>
int main()
{
    int i,t,l,k[1000],kk=1;
    char a[1000];
    memset(k,0,sizeof(k));
    scanf("%s",a);
    l=strlen(a);
    if(a[0]!='a')   {printf("NO\n");return 0;}
    if(l==1)    {printf("YES\n");return 0;}
    for(i=1;i<l;i++)
    {
        if (a[i]=='a')  k[i]=1;
        else for(t=0;t<i;t++)
            if(a[t]==a[i]-1)    k[i]=1;
    }
    for(i=1;i<l;i++)
        if(!k[i])   kk=0;
    if(kk)  printf("YES\n");
    else printf("NO\n");
    return 0;
}
