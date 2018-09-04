#include<stdio.h>
void main()
{
    int n,i,j,k,a[20][20];
    printf("Input the number of lines: ");scanf("%d",&n);
    for(i=1;i<=n;i++)
        {
            a[i][1]=1;a[i][i]=1;                //确定边界
        }
    for(i=3;i<=n;i++)
        for(j=2;j<=i-1;j++)
            a[i][j]=a[i-1][j-1]+a[i-1][j];      //递推赋值
        for(i=1;i<=n;i++)
        {
            for(k=1;k<=40-3*i;k++)
                printf(" ");                    //空格输出
            for(j=1;j<=i;j++)
                printf("%6d",a[i][j]);          //数字输出
            printf("\n");
        }
}
