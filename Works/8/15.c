#include<stdio.h>
double a[4][5]
double aver(double a[][5],int n)
{
    int i;
    double sum=0;
    for(i=0;i<4;i++)
    {
        sum+=a[i];
    }
    return sum/4;
}
int main()
{
    f=fopen("input.txt","r");
    fscanf("")
    double a[4][5];
    int n;
    printf("Which subject's average score do you want to know: ");scanf("%d",&n);
        printf("The No.%d subject's average score is: %ld",n,aver(a,n-1));
    printf("")
}
