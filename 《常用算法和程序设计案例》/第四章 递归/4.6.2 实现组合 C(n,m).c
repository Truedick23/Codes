/*  注意到组合与组成元素的顺序无关，约定组合中的组成元素按递增排序。
    因而，把以上排序顺序中的约束条件等于”==“改为大于等于”>=“，然而这样做了很多无效操作，效率低。
    */

#include<stdio.h>
int m,n,a[100];
long s=0;
void main()
{
    int c(int k);
    printf(" Input n(n<10):");scanf("%d",&n);
    printf(" Input m(1<m<=n):");scanf("%d",&m);
    c(1);
    printf("\n C(%d,%d)=%ld \n",n,m,s);
}
int c(int k)
{
    int i,j;
    if(k<=m)
    {
        a[0]=0;
        for(i=a[k-1]+1;i<=n+k-m;i++)
        {
            a[k]=i;                 //对第k个数赋值i，保证a[k]比a[k-1]大，而且小于题设上限
            if(k==m)                //若数已经取够，则实施输出
            {
                s++;printf(" ");
                for(j=1;j<=m;j++)
                    printf("%d",a[j]);
                if(s%10==0) printf("\n");
            }
            else
                c(k+1);         //若数还没有取够，则继续进行取值
        }
    }
    return s;
}
