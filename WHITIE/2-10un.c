#include<stdio.h>
int main()
{
    int n,m,k,a[9],i1,i2,t;
    for(n=100;3*n<100;n++)
    {
        t=1;
        m=2*n;
        k=3*n;
        a[0]=n/100;
        a[1]=(n-a[0]*100)/10;
        a[2]=n%10;
        a[3]=m/100;
        a[4]=(m-a[3]*100)/10;
        a[5]=m%10;
        a[6]=k/100;
        a[7]=(k-a[6]*100)/10;
        a[8]=k%10;
        for(i1=0;i1<9;i1++)
        {
            if(a[i1]==0)    t=0;break;
        }
        for(i1=1;i1<9;i1++)
        {
            for(i2=0;i2<i1;i2++)
            {
                if(a[i1]==a[i2])    t=0;break;
            }
        }
        if(t)   printf("%d %d %d\n",n,m,k);
    }
}
