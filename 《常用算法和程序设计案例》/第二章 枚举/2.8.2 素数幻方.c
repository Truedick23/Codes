/*定义素数幻方全是由素数构成的且各行、各列与两对角线之和均相等的方阵，从规定区间内寻找九个素数，构成一个三阶素数幻方
        即  n-x  n+w n-y
            n+z  n   n-z
            n+y  n-w n+x            设方阵中间数为n，每行每列每对角线之和为s，注意到:
                                    （中间一行）+（中间一列）+（两对角线）=4s
                                    方阵所有九个数之和=3s            故得到n=s/3

            为避免重复，约定两对角线的3个数为大数在下（x>0,y>0），下面一行大数在右（x>y）
            满足条件时   z=x-y, w=x+y (x>y)      同时易知9个素数中不能有偶素数2，因而x,y,z,w都只能是正偶数*/

#include<stdio.h>
#include<math.h>
int main()
{
    int c,d,j,k,n,t,t1,t2,w,x,y,z,m;
    int a[3000];
    m=0;
    printf("Input the range:");scanf("%d%d",&c,&d);
    if(c%2==0)  c=c+1;      //略过偶数
    if(c<3)  c=3;
    for(k=c;k<=d;k++)   a[k]=0;
    for(k=c;k<=d;k+=2)
    {
        for(t=0,j=3;j<=sqrt(k);j+=2)
        if(k%j==0) {t=1;break;}             //列举奇数，若k为素数，赋值a[k]=1
        if(t==0)    a[k]=1;
    }
    for(n=c;n<=d-8;n=n+2)
    {
        if(a[n]==0) continue;               //排除正中数为非素数
        for(y=2;y<=n-3;y+=2)
        for(x=y+2;x<=n-1;x+=2)
        {
            z=x-y;w=x+y;
            if(x==2*y||n-w<c||n+w>d)        //x=2y时将导致z=y，出现相同的数；而由于n-w和n+w分别为最大和最小值，故需保证它们两个在范围之内
                continue;
            t1=a[n-w]*a[n+w]*a[n-z]*a[n+z];
            t2=a[n-x]*a[n+x]*a[n-y]*a[n+y];
            if(t1*t2==0)    continue;               //控制其余数均为素数
            m++;
            printf("  NO%d:\n",m);
            printf("%5d%5d%5d\n",n-x,n+w,n-y);
            printf("%5d%5d%5d\n",n+z,n,n-z);
            printf("%5d%5d%5d\n",n+y,n-w,n+x);
        }
    }
    printf(" The are %d solution in total. \n",m);
}
