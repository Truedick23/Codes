#include<stdio.h>
int main()
{
    int i,n,*p,**m,a[100];
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(p=a,m=&p;p-a<n;p++)
    {
        if(*p>**m)  m=&p;
    }
    printf("The maximum number is: %d",*(*m));
    return 0;
}
