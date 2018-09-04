#include<stdio.h>
int main()
{
    int a[][5]={{48,21,77,49,999},{21,65,23,12,23},{32,42,23,12,52},{23,65,22,12,54},{23,12,53,23,87},{23,231,123,32,32},{23,412,52,54,23},{23,12,51,23,54},{123,45,123,43,53},{123,1,64,345,55}};
    int i1,i2;
    printf("The original array is:\n");
    for(i1=0;i1<10;i1++)
    {
        for(i2=0;i2<5;i2++)
        {
            printf("%d\t",a[i1][i2]);
        }
        putchar('\n');
    }
    printf("\n\n");
    double stuaver(int x,int m[][5]);
    double subaver(int y,int m[][5]);
    double sq(int m[][5]);
    void max(int m[][5]);
    for(i1=0;i1<10;i1++)
    {
        printf("The No.%d student's average score is: %.2f\n",i1+1,stuaver(i1,a));
    }
    putchar('\n');
    for(i2=0;i2<5;i2++)
    {
        printf("The No.%d subject's average score is: %.2f\n",i2+1,subaver(i2,a));
    }
    putchar('\n');
    max(a);
    putchar('\n');
    printf("The variance is: %.2f\n",sq(a));
}

double stuaver(int x,int m[][5])
{
    int i,sum;
    for(i=0,sum=0;i<5;i++)
    {
        sum=sum+m[x][i];
    }
    return sum/5;
}

double subaver(int y,int m[][5])
{
    int i,sum;
    for(i=0,sum=0;i<10;i++)
    {
        sum=sum+m[y][i];
    }
    return sum/10;
}

void max(int m[][5])
{
    int l[5],x[5],y[5],i1,i2,mm,xx,yy;
    for(i1=0;i1<5;i1++)
    {
        for(i2=0,l[i1]=m[i1][0],x[i1]=0,y[i1]=0;i2<10;i2++)
        {
            if(l[i1]<m[i1][i2])
            {
                l[i1]=m[i1][i2];
                x[i1]=i1;
                y[i1]=i2;
            }
        }
    }
    for(i1=0,mm=l[0],xx=x[0],yy=y[0];i1<5;i1++)
    {
        if(l[i1]>mm)
        {
            mm=l[i1];
            xx=x[i1];
            yy=y[i1];
        }

    }
    printf("The maximum number is: %d\nWhich position is:\tX=%d\tY=%d\n",mm,xx,yy);
}

double sq(int m[][5])
{
    int sum1,sum2,i;
    for(i=0,sum1=0,sum2=0;i<10;i++)
    {
        sum1=sum1+stuaver(i,m)*stuaver(i,m);
        sum2=sum2+stuaver(i,m);
    }
    return sum1/i-(sum2/10)*(sum2/10);
}
