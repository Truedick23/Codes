#include<stdio.h>
int month2(int x,int n)
{
    if(x%400==0||(x%100!=0&&x%4==0))
        {
            n=29;
        }
        else
        {
            n=28;
        }
        return(n);
}

int main()
{
    int d2,result,y,m,d;
    while(scanf("%d%d%d",&y,&m,&d)!=EOF)
    {
        d2=month2(y,d2);
        switch(m)
        {
        case 1:
            {
                result=d;
                break;
            }
        case 2:
            {
                result=31+d;
                break;
            }
        case 3:
            {
                result=31+d2+d;
                break;
            }
        case 4:
            {
                result=62+d2+d;
                break;
            }
        case 5:
            {
                result=92+d2+d;
                break;
            }
        case 6:
            {
                result=123+d2+d;
                break;
            }
        case 7:
            {
                result=153+d2+d;
                break;
            }
        case 8:
            {
                result=184+d2+d;
                break;
            }
        case 9:
            {
                result=215+d2+d;
                break;
            }
        case 10:
            {
                result=245+d2+d;
                break;
            }
        case 11:
            {
                result=276+d2+d;
                break;
            }
        case 12:
            {
                result=306+d2+d;
                break;
            }
        default: break;
        }
        printf("%d\n",result);
    }
    return 0;
}
