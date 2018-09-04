#include<stdio.h>
#include<math.h>
int o(int x)
{
    int i,l,result;
    int num[6];
    for(i=0;i<6;i++)
    {
        if(x/pow(10,i)>=1&&x/pow(10,i)<10)
            break;
    }
    l=i;
    for(i=l;i>=0;i--)
    {
        num[i]=x/pow(10,i);
        x=x-num[i]*pow(10,i);
    }
    for(i=0,result=0;i<l;i++)
    {
        result=result+num[i]*pow(16,l-i);
    }
    return result;
}

int main()
{
    int a;
    scanf("%d",&a);
    printf("%d",o(a));
    return 0;
}
