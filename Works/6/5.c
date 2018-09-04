#include<stdio.h>
int main()
{
    int a[10],i,t;
    printf("Please enter an array:\n");
    for(i=0;i<10;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<6;i++)
    {
        t=a[i];
        a[i]=a[9-i];
        a[9-i]=t;
    }
    printf("The changed array is:\n");
    for(i=0;i<10;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}
