/*  快速排序又称为分区交换排序，其基本思想是分治，即分而治之：
    在待排序的n个数据r[1,2,...,n]中任取一个数（例如r[1]）作为基准，把其余n-1个数据分为两个区，
    小于基准的数放在左边，大于基准的数放在右边。
    这样形成两个待排序数据的两个子列，然后对这两个子列分别重复上述过程，直到所有元素排到位
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int r[20001];
void main()
{
    int i,n,t;
    void qk(int m1,int m2);
    t=time(0)%1000;srand(t);                    //随机数发生器初始化
    printf(" Input n:");scanf("%d",&n);
    printf("The %d integer that participate in are(is): \n",n);
    for(i=1;i<=n;i++)
    {
        r[i]=rand()%(4*n)+10;                   //随机产生并输出n个整数
        printf("%5d",r[i]);
    }
    qk(1,n);                                //调用递归函数
    printf("\n Sorted: \n",n);
    for(i=1;i<=n;i++)
        printf("%5d",r[i]);
    printf("\n");
}
void qk(int m1,int m2)
{
    int i,j;
    if(m1<m2)
    {
        i=m1;j=m2;r[0]=r[i];                //用r[0]标识基准数，将r[i]定为基准
        while(i!=j)
        {
            while(r[j]>=r[0]&&j>i)          //从右至左逐个检查是否大于基准
                j--;
            if(i<j) {r[i]=r[j];i++;}        //若两个指针没有交叉，则把小于基准的那个数(即r[j])赋给r[i]，i左移一位
            while(r[j]<=r[0]&&j>i)          //从左至右逐个检查是否小于基准
                i++;
            if(i<j) {r[j]=r[i];j--;}        //同理，把大于基准的数(r[i])赋给r[j]，j右移一位
        }
        r[i]=r[0];                          //最后把基准数赋给r[i]
        qk(m1,i-1);qk(i+1,m2);              //在i两边继续分区调用
    }
    return;
}
