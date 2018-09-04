#include<stdio.h>
void input(int x[10])
{
    int *p;
    for(p=x;p<(x+10);p++)
    {
        scanf("%d",p);
    }
}

void sort(int a[10])
{
    int *p,*max,*min;
    for(p=a,max=a,min=a;p<(a+10);p++)
    {
        if(*p>*max)  max=p;
        if(*p<*min)  min=p;
    }

    swap(max,a+9);
    swap(min,a);
}

void swap(int *x,int *y)
{
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}

void output(int a[10])
{
    int *p;
    for(p=a;p<(a+10);p++)
    {
        printf("%d ",*p);
    }
}

int main()
{
    int a[10];
    input(a);
    sort(a);
    output(a);
    return 0;
}
