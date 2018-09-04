#include<stdio.h>
int main()
{
    int i,j,a[10],iTemp,iPos;
    {input}
    for(i=0;i<9;i++)
    {
        iTemp=a[i];
        iPos=i;
        for(j=i+1;j<10;j++)
        {
            if(a[j]<iTemp)
            {
                iTemp=a[j];
                iPos=j;
            }
        }
        a[iPos]=a[i];
        a[i]=iTemp;
    }
    {output}
}
