#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
    char s[100],*p,*head;int n=0,m=0,c=0,i;double a[100];
    memset(a,0,sizeof(a));
    scanf("%s",s);
    p=s+strlen(s);
    head=s;
    for(i=strlen(s);i>=0;p--,i--)
    {
        if(*p>='0'&&*p<='9')
            {
                m++;c=1;
            }
        else
        {
            c=0;m=0;
            if(head-p!=strlen(s)&&*(p+1)>='0'&&*(p+1)<='9')    n++;
        }
        if(c)
        {
            a[n]+=(*p-48)*pow(10,m);
        }
    }
    for(i=0;i<n;i++)
        printf("%  .0f  ",a[i]/10);
    printf("\nAs you can see, there are %d solutions! ",n);
    return 0;
}
