/*�۲�õ������ԳƷ��������������и���һ���Գ��ᣬ�����Գ�������4��С�����������Ϊ�ԶԳ���������ݼ����Գ���Ϊm=(n+1)/2,
            ����a[i][j]���ԣ����Խ��ߣ����������£���i=j���ζԽ�����i+j=n+1���ʽ������Ϊ�ϡ����ҡ����ĸ���*/

#include<stdio.h>
#include<math.h>
int main()
{
    int i,j,m,n,a[30][30];
    scanf("%d",&n);                 //ȷ������
    if(n%2==0)
    {
        printf("Single only!");return 0;
    }
    m=(n+1)/2;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
    {
        if(i+j<=n+1&&i<=j||i+j>=n+1&&i>=j)
            a[i][j]=m-abs(m-j);         //�ϡ��²���ֵ
        if(i+j<n+1&&i>j||i+j>n+1&&i<j)
            a[i][j]=m-abs(m-i);         //���Ҳ���ֵ
    }
    printf("Your:\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            printf("%3d",a[i][j]);
        printf("\n");
    }
    return 0;
}
