#include<stdio.h>
int main()
{
    int i1,i2,i3,m,n;
    scanf("%d%d",&m,&n);
    for(i1=0;i1<m;i1++)
    {
        for(i3=0;i3<=2*i1;i3++)
            {
                putchar(' ');
            }
        for(i2=0;i2<n;i2++)
        {
            printf("* ");
        }
    putchar('\n');
    }
    return 0;
}
