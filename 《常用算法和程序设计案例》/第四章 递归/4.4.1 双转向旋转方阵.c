/*  n����ת���󼴰�Ǯn^2��������1,2,3,....,n^2�����Ͻǿ�ʼ������������İ�˳���棩ʱ�뷽�������������Ƶ����ַ���
    �����˳תչ�������ö�ά����a[h][v]��ŷ����е�h�е�v��Ԫ�ء�

    �ݹ�������£���˳תΪ������
        ��n�׷�����⵽�ڷ�Ȧ����Ȧ����һ��n-2��˳ת���󣬳���ʼ����ͬ�⣬������ԭ������ͬ���������ԡ�
        ��ˣ����õݹ麯��t(b,s,d)������b��ÿ���������ʼλ�ã�d��Ϊ���鸳ֵ��������s�Ƿ���Ľ���
        s>1ʱ���ں����ڻ������t(b+1,s-2,d)��
        �ر�ģ���nΪ������s�ݼ�2��s=1ʱ������ֻ��һ��������Ȼ��ֵa[b][b]=d������
*/

#include<stdio.h>
int n,a[20][20]={0};
void main()
{
    int h,v,b,p,s,d;
    printf(" Input the degree n: ");scanf("%d",&n);
    printf(" Choose the direction, clockwise 1 or anticlockwise 2: ");scanf("%d",&p);          //����p���ж�˳ʱ�����ʱ��
    b=1;s=n;d=1;
    void t(int b,int s,int d);
    t(b,s,d);
    if(p==1)
        printf("Clockwise: \n");
    else
        printf("Anticlockwise: \n");
    for(h=1;h<=n;h++)
    {
        for(v=1;v<=n;v++)
            if(p==1)
            printf(" %3d",a[h][v]);                 //������ü���
            else
            printf(" %3d",a[v][h]);
        printf("\n");
    }
    return;
}
void t(int b,int s,int d)
{
    int j,h=b,v=b;
    if(s==0) return;                              //nΪż��ʱ���е������ı��˳�ѭ��
    if(s==1)
    {
        a[b][b]=d;return;                         //nΪ����ʱ��Ҫ����Ϊ��������ֵ
    }
    for(j=1;j<s;j++)
    {
        a[h][v]=d;v++;d++;                         //һȦ�����д����Ҹ�ֵ
    }
    for(j=1;j<s;j++)
    {
        a[h][v]=d;h++;d++;                          //һȦ�����д��ϵ��¸�ֵ
    }
    for(j=1;j<s;j++)
    {
        a[h][v]=d;v--;d++;                          //һȦ�����д��ҵ���ֵ
    }
    for(j=1;j<s;j++)
    {
        a[h][v]=d;h--;d++;                          //һȦ�����д��µ��ϸ�ֵ
    }
    t(b+1,s-2,d);                                   //���õݹ麯��
}
