/*  给定由n个整数（可能有负数）组成的序列a1,a2,...,an，
    要在这n个数中选取相邻的一段ai,a(i+1),...aj(1<=i<=j<=n)，使其和最大，输出最大的和，
    当所有整数均为负整数时，定义最大子段和为0。
    令b[j]=max{k=iΣj a[k]},i<=j<=n，根据此定义，当b[j-1]>0时，b[j]=b[j-1]+a[j]，否则b[j]=a[j]。
    故可得b[j]的动态规划递归式：
            b[j]=max{b[j-1]+a[j],a[j]}，1<=j<=n      */

#define NUM 1001
int a[NUM];
int MaxSum(int n,int &besti,int &bestj)
{
    int sum=0;
    int b=0;
    int begin=0;
    for(int i=1;i<=n;i++)
    {
        if(b>0) b+=a[i];
        else {b=a[i];begin=i;}
        if(b>sum)
        {
            sum=b;
            besti=begin;
            bestj=i;
        }
    }
    return sum;
}
