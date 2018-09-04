#include<stdio.h>
int main()
{
    int n,i,a[8]={1,1,1,1,1,1,1,1};
    int mark=1;
    int *p;
    for(i=0;i<8;i++)
    {
        n=1;
        if(a[i])
        {
            if(n==3)
            {
                a[i]=0;
                mark++;
                i=0;
                n=1;
            }
            else    n++;
        }
        if(i==7)  i=0;
        if(mark==8) break;
    }
    printf("%d\n",i);
    for(i=0;i<8;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}
