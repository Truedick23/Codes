#include<stdio.h>
int main()
{
    int a[4][4];
    int j,k,m,n,max,min,i,l;
    for(m=0;m<4;m++)
    {
        for(n=0;n<4;n++)
        {
            scanf("%d",&a[m][n]);
        }
    }
    for(m=0;m<4;m++)
    {
        for(n=0,j=0;n<4;n++)
        {
            if(a[m][n]>a[m][j])
                j=n,i=1;
        }
        for(l=0;l<4;l++)
            {
                if(a[l][j]<a[m][j])
                i=0;
            }
            if(i)   printf("a[%d][%d]=%d\n",m,j,a[m][j]);
    }
    return 0;
}
