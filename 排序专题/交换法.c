#include<stdio.h>
int main()
{
    int i,j,a[10],iTemp;
    //input
    for(i=0;i<9;i++)
    {
        for(j=i+1;j<10;j++)
        {
            if(a[j]<a[i])
            {
                iTemp=a[i];
                a[i]=a[j];
            }
        }
    }
    //output
}
