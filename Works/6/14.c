#include<stdio.h>
#include<string.h>
int main()
{
    int k=0,i,l1,l2,m;
    char a[100],b[100];
    gets(a);
    gets(b);
    l1=strlen(a);
    l2=strlen(b);
    if(l1>l2)k=1;
    if(l1<l2)k=2;
    if(!k)
    {
        for(i=0;i<l1;i++)
        {
            if(a[i]>b[i])
            {
                k=1;
                m=a[i]-b[i];
            }
            if(a[i]<b[i])
            {
                k=2;
                m=a[i]-b[i];
            }
        }
    }
    if(k==1)
    {
        printf("a is bigger\na-b=%d",m);
    }
    if(k==2)
    {
        printf("b is bigger\na-b=%d",m);
    }
    if(!k)
    {
        printf("a=b");
    }
    return 0;
}
