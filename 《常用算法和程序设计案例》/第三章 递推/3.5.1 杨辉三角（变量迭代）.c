/*  注意到杨辉三角实际上是二项式展开式各项的系数，即第n+1行的n+1个数分别是C(n,0),C(n,1),C(n,2)....C(n,n)
    又存在组合公式：
    C(n,0)=1
    C(n,k)=(n-k+1)/k*c(n,k-1)*/

#include<stdio.h>
void main()
{
    int m,n,cnm,k;
    printf("The number of lines:");scanf("%d",&n);
    for(k=1;k<=40;k++)  printf(" ");
    printf("%6d\n",1);                      //输出第一行
    for(m=1;m<=n-1;m++)
    {
        for(k=1;k<=40-3*m;k++)
            printf(" ");
        cnm=1;
        printf("%6d",cnm);
        for(k=1;k<=m;k++)
        {
            cnm=cnm*(m-k+1)/k;
            printf("%6d",cnm);
        }
    printf("%\n");
    }
}
