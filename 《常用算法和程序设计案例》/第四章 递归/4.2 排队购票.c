/*情景设置：有m+n个人排队等候购票，其中有m个人手持50元的钞票，另外n个人手持100元的钞票。
            求出这m+n个人排队购票，使没有零钱的售票处不至出现找不开钱局面的不同排队种数
            现用f(m,n)来表示此时种数。分三种情况讨论：
            1) n=0
                此时意味着所有人都拿着50元，排队种数为1，即f(m,0)=1
            2) m<n
                此时持50元的人少于持100元的人，必然找不开钱，即f(m,n)=0
            3) 其他情况
                思考有m+n个人排队的情况，此时可分两种情况：
                a.  第m+n个人手持100元，所以之前有m人手持50元，n-1人手持100
                b.  第m+n个人手持50元，m-1人手持50，n人手持100
        故：f(m,n)=f(m,n-1)+f(m-1,n)
                */
long f(int j,int i)
{
    long y;
    if(i==0)    y=1;
    else if(j<i)    y=0;
    else y=f(j-1,i)+f(j,i-1);
    return y;
}
#include<stdio.h>
void main()
{
    int m,n;
    printf("Input m, n: ");scanf("%d%d",&m,&n);
    printf(" f(%d,%d)=%ld.\n",m,n,f(m,n));
}
