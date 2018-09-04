#include<stdio.h>
#include<math.h>
int main()
{
    int t,m,n,i1,i2;
    while(scanf("%d",&t)!=EOF)
    {
        for(i1=0;i1<t;i1++)
        {
            scanf("%d(%d)",&m,&n);
        }
        for(i2=0;i2<10;i2++)
        {
            if(m<pow(10,i2))
            break;
        }
        printf("%d",i2);
    }
}
