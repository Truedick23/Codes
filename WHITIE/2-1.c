#include<stdio.h>
#include<math.h>
int main()
{
    int a,i;
    while(scanf("%d",&a)!=EOF)
    {
        for(i=0;i<9;i++)
        {
            if((a/pow(10,i))<10)  break;
        }
        printf("%d\n",i+1);
    }

    return 0;
}
