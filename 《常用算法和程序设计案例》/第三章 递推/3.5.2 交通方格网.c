/*某城区的交通方格网如描述：
    城区中一座山占据了交通网中(3,2)、(4,2)和(4,3)，即这3个交叉点尚未开通，
    另有从(2,3)至(2,4)、(5,0)至(6,0)的两条路段正在维护，禁止通行
        试统计从起始点(0,0)到终点(m,n)的不同最短路线(不走回头路！！)的条数。
        输入正整数m,n（m<=20,n<=20），输出从起始点(0,0)到终点(m,n)的最短路线的条数。

分析：设f(x,y)为从起始点(0,0)到点(x,y)的不同最短路线的条数。注意到最短路线中点(x,y)的前一个点为(x-1,y)与(x,y-1)这两个，则：
        1）递推关系
                f(x,y)=f(x-1,y)+f(x,y-1)
        2）边界条件
                f(x,0)=1    （0<x<=5）
                f(x,0)=0    （5<x<-m）
                f(0,y)=1    （0<y<=n
        3）障碍处理
        对于被山占据的三点，令
                f(3,2)=f(4,2)=f(4,3)=0
        从(2,3)至(2,4)段禁止通行，则对f(2,4)的赋值固定
                f(2,4)=f(1,4)
        */

#include<stdio.h>
void main()
{
    int m,n,x,y;long f[21][21];
    printf(" Input m,n:");scanf("%d%d",&m,&n);
    for(x=1;x<=5;x++)   f[x][0]=1;
    for(x=5;x<=m;x++)   f[x][0]=0;                  //设置边界
    for(y=1;y<=n;y++)   f[0][y]=1;
    for(x=1;x<=m;x++)
        for(y=1;y<=n;y++)
            if(x==3&&y==2||x==4&&y==2||x==4&&y==3)
                f[x][y]=0;                                  //被山占据三点设置
            else if(x==2&&y==4)
                f[x][y]=f[x-1][y];                          //禁止通行的路径的设置
            else
                f[x][y]=f[x-1][y]+f[x][y-1];                //其他点的递推
    printf("The number of shortest path is: %ld\n",f[m][n]);
}
