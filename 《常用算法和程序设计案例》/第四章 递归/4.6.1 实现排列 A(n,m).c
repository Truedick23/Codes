/*  ����Ҫ�󣺶�ָ����������m��n��Լ��1<m<=n��������ʵ�ִ�n����ͬԪ������ȡm��Ԫ�ص�ÿһ����*/

#include<stdio.h>
int m,n,a[30];long s=0;
void main()
{
    int p(int k);
    printf(" Input n(n<10): ");scanf("%d",&n);
    printf(" Input m(1<m<=n): ");scanf("%d",&m);
    p(1);
    printf("\n There are %ld results.\n",s);
}
int p(int k)
{
    int i,j,u;
    if(k<=m)
    {
        for(i=1;i<=n;i++)
        {
            a[k]=i;     //��k����a[k]��ֵi������ʶu=0
            for(u=0,j=1;j<=k-1;j++)
                if(a[k]==a[j])          //��ǰ�������ͬ��ֵ�����ʶu=1
                u=1;
            if(u==0)            //����ǰ��������û��һ����ȣ����������Ƿ�ȡ��m����
            {
                if(k==m)
                {
                    s++;printf(" ");            //��ȡ����m���������ĸ�����һ������������
                    for(j=1;j<=m;j++)
                        printf("%d",a[j]);
                    if(s%10==0) printf("\n");
                }                               //��ʱ��δ����ѭ�������ǻص�iȡi+1��ʱ�򣬼���̽��
                else p(k+1);                    //��û��ȡ���������̽��a[k]����һ����a[k+1]�ٴδ�(1~n)��ȡֵ
            }
        }
    }                                       //���i����nʱ���Ѿ��о������������Σ�����������
    return s;
}
