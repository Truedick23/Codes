#include<stdio.h>
int main()
{
    int a[3][3];
    int i1,i2,(*p)[3],t;
    p=a;
    for(i1=0;i1<3;i1++)
    {
        for(i2=0;i2<3;i2++)
        {
            scanf("%d",*(p+i1)+i2);
        }
    }

    printf("\n");

    for(i1=0;i1<3;i1++)
    {
        for(i2=0;i2<3;i2++)
        {
            printf("%d ",a[i2][i1]);
        }
        printf("\n");
    }
    return 0;
}
