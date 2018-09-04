#include<stdio.h>
#define MINN 0.000001
int main()
{
    int i=1,m=1;
    double sum;
    while(1.0/i>=MINN)
    {
        sum+=1.0/i*m;
        i+=2;
        m*=-1;
    }
    printf("pi/4=%f",sum);
}
