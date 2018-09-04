/*  案例提出：在一个无序序列r(1),r(2),....,r(n)中，寻找第k小元素的问题称为选择。
                特别的，当k=n/2时，即寻找位于n个元素中的中间元素，称为中值问题
    设计思路：参照4.5.1的分区交换思路：
        在n个数中任取一个数作为基准，把其余的数据分为两个区，小于基准的数放左边，大于基准放右边，
        基准定位在s，则：
        (1)若s=k，基准数即为所寻求的第k小元素。
        (2)若s>k，可知左边小于该基准数的个数s-1>=k，则在左边继续分区
        (2)若s<k，可知所寻求的第k小元素在右边子区，则在右边继续分区
                其后不断重复此过程，知道出现(1)时结束分区
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int m1,m2,k,r[20001];
void main()
{
    int i,j,n,t;
    int s(int m1,int m2,int k);
    t=time(0)%1000;srand(t);                //随机数发生器初始化
    printf(" Input the number of number that participate: ");scanf("%d",&n);
    printf(" Input the ranking of the number: ");scanf("%d",&k);
    printf(" The numbers are: \n");
    for(i=1;i<=n;i++)
    {
        t=rand()%(4*n)+10;                  //随机产生并输出n个整数
        for(j=1;j<i;j++)
            if(t==r[j]) break;
        if(j==i)
        {
            r[i]=t;printf(" %d",r[i]);
        }
        else {i--;continue;}
    }
    s(1,n,k);                       //调用递归函数
    printf(" \n The integer among %d that ranked %d is %d. \n",n,k,r[k]);
}
int s(int m1,int m2,int k)
{
    int i,j;
    if(m1<m2)
    {
        i=m1;j=m2;r[0]=r[i];                //定义第i个数为分区基准
        while(i!=j)
        {
            while(r[j]>=r[0]&&j>i)              //从右至左逐个检查是否大于基准
                j--;
            if(i<j) {r[i]=r[j];i++;}            //把小于基准的一个数赋给r[j]
            while(r[j]<=r[0]&&j>i)              //从左至右逐个检查是否小于基准
                i++;
            if(i<j) {r[j]=r[i];j--;}            //把大于基准的一个数赋给r[j]
        }
        r[i]=r[0];                              //把基准的值赋给r[j]
    }
    if(i==k)    return r[k];
        else if(i>k)    return s(m1,i-1,k);
    else return s(i+1,m2,k);
}


