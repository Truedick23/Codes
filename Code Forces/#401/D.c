#include<stdio.h>
#include<string.h>
int main()
{
    int n,i,maxl=1,t,p,k=0,m;
    char a[5000][5000];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%s",a[i]);
    }
    for(i=1;i<n-1;i++)
    {
        for(m=1;m<strlen(a[i]);m++)
            for(t=i+1;t<n;t++)
            if(a[i][m]>a[t][m]) {k=1;break;}
        if(k)   a[i][m]='\n';
        k=0;
    }
    for(i=0;i<n;i++)
        printf("%s\n",a[i]);
    return 0;
}
