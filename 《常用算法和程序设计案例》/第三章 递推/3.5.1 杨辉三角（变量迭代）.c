/*  ע�⵽�������ʵ�����Ƕ���ʽչ��ʽ�����ϵ��������n+1�е�n+1�����ֱ���C(n,0),C(n,1),C(n,2)....C(n,n)
    �ִ�����Ϲ�ʽ��
    C(n,0)=1
    C(n,k)=(n-k+1)/k*c(n,k-1)*/

#include<stdio.h>
void main()
{
    int m,n,cnm,k;
    printf("The number of lines:");scanf("%d",&n);
    for(k=1;k<=40;k++)  printf(" ");
    printf("%6d\n",1);                      //�����һ��
    for(m=1;m<=n-1;m++)
    {
        for(k=1;k<=40-3*m;k++)
            printf(" ");
        cnm=1;
        printf("%6d",cnm);
        for(k=1;k<=m;k++)
        {
            cnm=cnm*(m-k+1)/k;
            printf("%6d",cnm);
        }
    printf("%\n");
    }
}
