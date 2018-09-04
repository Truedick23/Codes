#include<stdio.h>

int feb(int year)
{
    int d;
    if(year%400==0||(year%4==0&&year%100!=0))   d=29;
    else    d=28;
    return d;
}

int total(int x,int y,int d,int f)
{
    int t=0;
    switch(y)
    {
    case 1:
        {
            t=d;
        }
    case 2:
        {
            t=31+d;
        }
    case 3:
        {
            t=31+f+d;
        }
    case 4:
        {
            t=62+f+d;
        }
    case 5:
        {
            t=92+f+d;
        }
    case 6:
        {
            t=123+f+d;
        }
    case 7:
        {
            t=153+f+d;
        }
    case 8:
        {
            t=184+f+d;
        }
    case 9:
        {
            t=215+f+d;
        }
    case 10:
        {
            t=245+f+d;
        }
    case 11:
        {
            t=276+f+d;
        }
    case 12:
        {
            t=306+f+d;
        }
    default:
        {
            printf("Wrong month\n");
        }
    }
    return t;
}

int main()
{
    int y,m,d,sum,f;
    scanf("%d%d%d",&y,&m,&d);
    f=feb(y);
    sum=total(y,m,d,f);
    printf("%d\n",sum);
    return 0;
}

