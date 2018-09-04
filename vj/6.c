#include<stdio.h>
int main()
{
    int i1,i2,t,l,m[500],n[500],c1,c2,x=0,y,j=1,k;
    scanf("%d",&t);
    for(i1=0;i1<t;i1++)
    {
        scanf("%d",&l);
        for(i2=0;i2<l;i2++)
        {
            scanf("%d%d",&m[i2],&n[i2]);
        }
        for(c1=0;c1<l;c1++)
        {
            for(c2=0;c2<c1;c2++)
            {
                if(m[c1]==m[c2])
                {
                    x++;
                    if(n[c1]+n[c2]>64)
                    {
                        x=x-((n[c1]+n[c2])/64);
                    }
                }
            }
        }
        y=t-x;
        if(y>36)
        {
            j=j+y/36;
        }
    printf("%d\n",j);
    }
    return 0;
}
