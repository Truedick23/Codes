#include<stdio.h>
int main()
{
    int i,a[10],iTemp,iPos;
    //input
    for(i=1;i<10;i++)
    {
        iTemp=a[i];
        iPos=i-1;
        while((iPos>=0)&&(iTemp<a[iPos]))
        {
            a[iPos+1]=a[iPos];
            iPos--;
        }
        a[iPos+1]=iTemp;
    }
    //output
}
