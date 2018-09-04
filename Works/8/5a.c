#include<stdio.h>
int main()
{
    int a[100],*p,i,n,l,j=1,t,lenth;
    scanf("%d%d",&l,&t);
    for(i=0;i<l;i++)
    {
        a[i]=i+1;
    }
    lenth=l;
    if(lenth==1)    printf("The last is 1");
    for(p=a;;p++)
    {
        if(p-a==lenth)
        {
            p=a;
        }
        if(l==0)
        {
            printf("\nthe last is %d",p-a);
            break;
        }
        if(*p!=0)
        {
          if(j==t)
            {
                printf("%d ",p-a+1);
                *p=0;
                l--;
                j=1;
                continue;
            }
            else    j++;
        }

    }
    return 0;
}
