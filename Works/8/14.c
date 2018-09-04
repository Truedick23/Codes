#include<stdio.h>
#define MAXN 100000
void sort(int a[],int n)
{
    int *i,*p,mid;
    mid=n/2;
    for(i=a,p=a+n-1;i<(a+mid);i++,p--)
        swap(i,p);
    return;
}

void swap(int *x,int *y)
{
    int t;
    t=*x;
    *x=*y;
    *y=t;
}

void input(int a[],int n)
{
    int i;
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    return;
}

void output(int a[],int n)
{
    int *i;
    printf("Backwards:\n");
    for(i=a;i<(a+n);i++)
        printf("%d ",*i);
    printf("\n");
}

int main()
{
    int a[MAXN],n;
    printf("Please input the length of the array:");
        scanf("%d",&n);
    printf("Original array:\n");
    input(a,n);
    sort(a,n);
    output(a,n);
    return 0;
}
