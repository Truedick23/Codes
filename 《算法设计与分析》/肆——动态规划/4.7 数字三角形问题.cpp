/*  �������������⣺�����һ���㷨��������������εĶ����׵�һ��·����ʹ��·�������������ܺ����
    ���¶��������ߵ�״̬ת�Ʒ��̣�
        tri[i][j]=tri[i][j]+max{tri[i+1][j],tri[i+1][j+1]}������i=n-1,n-3,...,0��0<=j<=i    */

#define NUM 100
int tri[NUM][NUM];
int triangle(int n)
{
    int i,j;
    for(i=n-1;i>=0;i--)
    for(j=0;j<=i;j++)w
    {
        if(tri[i+1][j]>tri[i+1][j+1])
            tri[i][j]+=tri[i+1][j];
        else tri[i][j]+=tri[i+1][j+1];
    }
    return tri[0][0];
}
