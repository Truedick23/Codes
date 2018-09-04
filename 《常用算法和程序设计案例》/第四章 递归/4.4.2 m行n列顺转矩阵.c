/*  当数阵的行列数不相等时，数阵称为矩阵。
    递归设计：
    设置二维数组a[h][v]存放第h行第v列的整数，
    同方阵，外圈内是一个m-2行n-2列阶顺转矩阵，且特性属性未变
    因此设置函数t(b,s,d)，其中b是每个矩阵的起始位置，d为赋值整数，s=min(m,n)是矩阵阶数
    s>1时，函数中调用t(b+1,s-2,d)
    函数的调用到d=m*n停止

    注意到当s=min(m,n)为奇数时，最后一圈（s=1）只有一半。为避免最后一圈的另一半再复制可能因数据覆盖导致出错，当完成d=m*n时，即返回，作为递归出口。
*/

#include<stdio.h>
int m,n,a[20][20]={0};
void main()
{
    int h,v,b,s,d;
    printf("Input m, n:");scanf("%d%d",&m,&n);
    s=m>n?n:m;                          //求出矩阵的阶数
    b=1;d=1;
    void t(int b,int s,int d);
    t(b,s,d);
    printf(" %d × %d clockwise matrix: \n",m,n);
    for(h=1;h<=m;h++)
    {
        for(v=1;v<=n;v++)
            printf(" %3d",a[h][v]);
        printf("\n");
    }
    return;
}
void t(int b,int s,int d)
{
    int j,h=b,v=b;
    if(s<=0)    return;             //一般递归出口
    if(s==1&&m==n)
    {
        a[h][v]=d;return;           //n=m且n为奇数时的递归出口
    }
    for(j=1;j<=n+1-2*b;j++)
    {
        a[h][v]=d;v++;d++;          //一圈的上行从左至右递增
    }
    for(j=1;j<=m+1-2*b;j++)
    {
        a[h][v]=d;h++;d++;          //一圈的右列从上至下递增
    }
    for(j=1;j<=n+1-2*b;j++)
    {
        a[h][v]=d;v--;d++;          //一圈的下列从右至左递增
        if(d>m*n)   break;          //min(m,n)为奇数且n>m时停止循环
    }
    for(j=1;j<=m+1-2*b;j++)
    {
        a[h][v]=d;h--;d++;          //一圈的左列从下至上递增
        if(d>m*n)   break;          //min(m,n)为偶数或者n<m时停止循环
    }
    t(b+1,s-2,d);                   //调用递归函数
}
