#include<stdio.h>
int main()
{
    long c,i,j,n,s;
    scanf("%ld",&n);
    c=0;
    for(i=1;i<=(n-1)/2;i++)                                     //ö�������ʼ��
    {
        s=0;
        for(j=i;j<=(n+1)/2;j++)                                 //ö����������
        {
            s=s+j;
            if(s>=n)
            {if(s==n)
                {
                    c++;printf(" %d:%d+...+%d\n",c,i,j);        //ͳ�Ʋ����һ����
                }
                break;
            }
        }
                                          //�����ĸ���
    } printf("%d\n",c);
    return 0;
}
