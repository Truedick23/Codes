#include<stdio.h>
int P1[4]={2,2,2,2},P2[4]={2,2,2,2},a[5][5];
/*void input(a[5][5])
{
    int i1,i2;
    for(i1=0;i1<5;i1++)
    {
        for(i2=0;i2<5;i2++)
        {
            scanf("%d",*(a+i1)+i2);
        }
    }
}*/

void swap(int *a,int *b)
{
    int t;
    t=*a;
    *a=*b;
    *b=t;
}

void engagemax(int a[5][5])
{
    int i1,i2,p1=0,p2=0,max=a[0][0];
    for(i1=0;i1<5;i1++)
    {
        for(i2=0;i2<5;i2++)
        {
            if(a[i1][i2]>max)  {p1=i1;p2=i2;max=a[i1][i2];}
        }
    }
    swap(*(a+2)+2,*(a+p1)+p2);
}

void engage(int a[5][5],int x,int y)
{
    int i1,i2,p1=2,p2=3,t,mark=1,max=a[2][3];
    for(i1=0;i1<5;i1++)
    {
        for(i2=0;i2<5;i2++)
        {

            for(t=0;t<4;t++)    {if(P1[t]==i1&&P2[t]==i2)   mark=0;}
            if(mark&&a[i1][i2]>max)  {p1=i1;p2=i2;max=a[i1][i2];}
            mark=1;
        }
    }
    swap(*(a+x)+y,*(a+p1)+p2);
}

void output(int a[5][5])
{
    int i1,i2;
    printf("\n");
    for(i1=0;i1<5;i1++)
    {
        for(i2=0;i2<5;i2++)
        {
            printf("%5d",a[i1][i2]);
        }
        printf("\n");
    }
}
int main()
{
    int a[5][5]={{1,99,100,32,45},{5,6,7,23,1},{78,42,6,9,1},{65,9,23,1,4},{34,12,39,12,4}};
    output(a);
    engagemax(a);
    output(a);
    engage(a,0,0);
    output(a);
    P1[1]=0;P2[1]=0;
    engage(a,0,4);
    output(a);
    P1[2]=0;P2[2]=4;
    engage(a,4,0);
    output(a);
    P1[3]=4;P2[3]=0;
    engage(a,4,4);
    output(a);
    return 0;
}
