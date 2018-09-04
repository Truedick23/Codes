#include<stdio.h>
int main()
{
    int a[10]={5,16,34,123,65,34,341,6,42,123};
    int i,t,p,temp,min;
    for(i=0;i<10;i++)
    {
        min=a[i];
        p=i;
        for(t=i+1;t<10;t++)
        {
            if(a[t]<min)
            {
                min=a[t];
                p=t;
            }
        }
        temp=a[p];
        a[p]=a[i];
        a[i]=temp;
    }

    for(i=0;i<10;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}
