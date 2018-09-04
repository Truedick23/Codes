#include<stdio.h>
int main()
{
    int a[100];
    int i=0,p=0,c,carnum,t;
    printf("Please choose your instruction:\n1-park\n2-drive away\n3-current status\n");
    while(scanf("%d",&c)!=EOF)
    {
        switch(c)
    {
    case 1:
        {
            printf("Car number:");
            scanf("%d",&carnum);
            a[i]=carnum;
            i++;
        }
    case 2:
        {
            i--;
        }
    case 3:
        {
            for(t=0;t<=i;t++)
            {
                printf("%d\n",a[t]);
            }
        }
    }
    }
    return 0;
}
