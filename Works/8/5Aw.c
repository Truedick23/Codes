#include<stdio.h>
int main()
{
    int n,i,a[8]={1,1,1,1,1,1,1,1};
    int mark=0;
    int *p;
    for(p=a;p<(a+8);p++)
    {
        n=1;
        if(*p)
        {
            if(n==3)
            {
                *p=0;
                mark++;
                p=a;
                n=1;
            }
            else    n++;
        }
        if(p-a==8)  p=a;
        if(mark==7) break;
    }
    printf("%d\n",*p);
    for(p=a;p<(a+8);p++)
    {
        printf("%d ",*p);
    }
    return 0;
}
