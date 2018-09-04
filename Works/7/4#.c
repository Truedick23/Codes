#include<stdio.h>
int main()
{
    int a[3][3]={{3,5,6},{7,8,1},{6,1,5}};
    int x=3,y=3,i1,i2;
    void s(int x[3][3]);
    for(i1=0;i1<x;i1++)
    {
        for(i2=0;i2<y;i2++)
        {
            printf("%d  ",a[i1][i2]);
        }
        putchar('\n');
    }
    putchar('\n\n');
    s(a);
    return 0;
}

void s(int x[3][3])
{
    int y[3][3];
    int i1,i2;
    for(i1=0;i1<3;i1++)
    {
        for(i2=0;i2<3;i2++)
        {
            y[i1][i2]=x[i2][i1];
        }
    }
    for(i1=0;i1<3;i1++)
    {
        for(i2=0;i2<3;i2++)
        {
            printf("%d  ",y[i1][i2]);
        }
        putchar('\n');
    }
}
