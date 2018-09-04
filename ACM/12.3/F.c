#include<stdio.h>
int main()
{
    char a[100][100];
    int m,n,i1,i2,i=0,t=0,num=0;
    scanf("%d%d",&m,&n);

    for(i=0;i<=m+1;i++)
    {
        a[i][0]='.';
        a[i][n+1]='.';
    }
    for(i=0;i<=n+1;i++)
    {
        a[0][i]='.';
        a[m+1][i]='.';
    }

    for(i1=1;i1<=m;i1++)
    {
        for(i2=1;i2<=n;i2++)
        {
            scanf("%c",&a[i1][i2]);
        }
    }
    printf("\n");
    for(i1=0;i1<m+2;i1++)
    {
        for(i2=0;i2<n+2;i2++)
        {
            printf("%c",a[i1][i2]);
        }
        printf("\n");
    }

    int dx[8]={1,1,1,0,0,-1,-1,-1};
    int dy[8]={0,-1,1,1,-1,0,1,-1};
    for(i1=1;i1<m+1;i1++)
    {
        for(i2=1;i2<m+1;i2++)
        {
            if(a[i1][i2]=='W'||a[i1][i2]=='w')
            {
                a[i1][i2]='.';
                for(i=0;i<8;i++)
                {
                    if(a[i1+dx[i]][i2+dy[i]]=='.')  t++;
                }

                if(t==8)    num++;
                else
                {
                   for(i=0;i<8;i++)
                    {
                        if(a[i1+dx[i]][i2+dy[i]]=='W')
                            a[i1+dx[i]][i2+dy[i]]='w';
                    }
                }
            }
        }
    }
    printf("\n\n%d",num);
    return 0;
}
