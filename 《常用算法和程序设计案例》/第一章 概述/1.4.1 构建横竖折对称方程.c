/*观察得到横竖对称方阵横向和纵向正中各有一个对称轴，两个对称轴所分4个小矩形区域表现为自对称轴向两侧递减，对称轴为m=(n+1)/2,
            对于a[i][j]而言，主对角线（坐上至右下）有i=j，次对角线有i+j=n+1，故将方阵分为上、左、右、下四个区*/

#include<stdio.h>
#include<math.h>
int main()
{
    int i,j,m,n,a[30][30];
    scanf("%d",&n);                 //确定阶数
    if(n%2==0)
    {
        printf("Single only!");return 0;
    }
    m=(n+1)/2;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
    {
        if(i+j<=n+1&&i<=j||i+j>=n+1&&i>=j)
            a[i][j]=m-abs(m-j);         //上、下部赋值
        if(i+j<n+1&&i>j||i+j>n+1&&i<j)
            a[i][j]=m-abs(m-i);         //左、右部赋值
    }
    printf("Your:\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            printf("%3d",a[i][j]);
        printf("\n");
    }
    return 0;
}
