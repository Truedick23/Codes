#include<stdio.h>
#include<math.h>
int main()
{
    int i,j,m,n,a[30][30];
    scanf("%d",&n);
    if(n%2==0)
    {
        printf("Single only!");return 0;
    }
    m=(n-1)/2;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
    {
        if(i<=m&&j<=m||i>m&&j>m)
            a[i][j]=abs(i-j);                   //���ϲ������²�Ԫ�ظ�ֵ
        if(i<=m&&j>m||i>m&&j<=m)
            a[i][j]=abs(i+j-n-1);               //���ϲ������²�Ԫ�ظ�ֵ
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
