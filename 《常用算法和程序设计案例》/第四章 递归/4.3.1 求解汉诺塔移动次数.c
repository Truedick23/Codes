/*  ����n��Բ�̴�A׮ȫ���Ƶ�C׮���ƶ�������
    ��n=1ʱ��һ�����ƶ�һ�μ����
    ��n=2ʱ�����������涨ֻ���ƶ�һ���̣��Ҳ����������С��֮�ϣ���
    ���ƶ�n���̵ĺ�ŵ����g(n)����ɡ�������3�����裺
    (1) ��n���������n-1�����ӽ���C׮��A׮�ƶ���B׮�ϣ���g(n-1)��
    (2) ��A׮�ϵĵ�n�������Ƶ�C׮��(1��)
    (3) ��B׮�ϵ�n-1�����ӽ���A׮�Ƶ�C׮�ϣ���Ҫg(n-1)��
    �������µ��ƣ�
            g(n)=2*g(n-1)+1
    */

#include<stdio.h>
void main()
{
    double g(int m);
    int n;
    printf(" Input the number of plate(s) n: ");scanf("%d",&n);
    if(n<=40)
        printf(" No.%d have been moved %.0f\n times.\n",n,g(n));
    else
        printf(" N0.%d have been moved %.4e\n times.\n",n,g(n));
}

double g(int m)
{
    double s;
    if(m==1)
        s=1;
    else
        s=2*g(m-1)+1;
    return s;
}
