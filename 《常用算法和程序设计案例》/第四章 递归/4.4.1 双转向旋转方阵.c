/*  n阶旋转方阵即把钱n^2个正整数1,2,3,....,n^2从左上角开始，由外层至中心按顺（逆）时针方向螺旋排列所称的数字方阵。
    设计以顺转展开，设置二维数组a[h][v]存放方阵中第h行第v列元素。

    递归设计如下（以顺转为例）：
        把n阶方阵从外到内分圈，外圈内是一个n-2阶顺转方阵，除起始数不同外，具有与原问题相同的特性属性。
        因此，设置递归函数t(b,s,d)，其中b是每个方阵的起始位置，d是为数组赋值的整数，s是方阵的阶数
        s>1时，在函数内还需调用t(b+1,s-2,d)，
        特别的，若n为奇数，s递减2至s=1时，方阵只有一个数，显然赋值a[b][b]=d，返回
*/

#include<stdio.h>
int n,a[20][20]={0};
void main()
{
    int h,v,b,p,s,d;
    printf(" Input the degree n: ");scanf("%d",&n);
    printf(" Choose the direction, clockwise 1 or anticlockwise 2: ");scanf("%d",&p);          //设置p来判断顺时针或逆时针
    b=1;s=n;d=1;
    void t(int b,int s,int d);
    t(b,s,d);
    if(p==1)
        printf("Clockwise: \n");
    else
        printf("Anticlockwise: \n");
    for(h=1;h<=n;h++)
    {
        for(v=1;v<=n;v++)
            if(p==1)
            printf(" %3d",a[h][v]);                 //输出采用技巧
            else
            printf(" %3d",a[v][h]);
        printf("\n");
    }
    return;
}
void t(int b,int s,int d)
{
    int j,h=b,v=b;
    if(s==0) return;                              //n为偶数时进行到了中心便退出循环
    if(s==1)
    {
        a[b][b]=d;return;                         //n为奇数时需要另外为中心数赋值
    }
    for(j=1;j<s;j++)
    {
        a[h][v]=d;v++;d++;                         //一圈的上行从左到右赋值
    }
    for(j=1;j<s;j++)
    {
        a[h][v]=d;h++;d++;                          //一圈的右列从上到下赋值
    }
    for(j=1;j<s;j++)
    {
        a[h][v]=d;v--;d++;                          //一圈的下行从右到左赋值
    }
    for(j=1;j<s;j++)
    {
        a[h][v]=d;h--;d++;                          //一圈的左列从下到上赋值
    }
    t(b+1,s-2,d);                                   //调用递归函数
}
