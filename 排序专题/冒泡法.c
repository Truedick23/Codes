#include<stdio.h>
int main()
{
    int i,j,a[10],iTemp;
    //input
    for(i=1;i<10;i++)
    {
        for(j=9;j>=i;j--)
        {
            if(a[j]<a[j-1])
            {
                iTemp=a[j-1];
                a[j-1]=a[j];           //�Ӻ���ǰ�����һ��Ԫ��С��ǰһ�����򻥻�
                a[j]=iTemp;
            }
        }
    }
    //output
}
