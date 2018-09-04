#include<stdio.h>
int main()
{
    int d,i,m[156];
    scanf("%d",&d);
    for(i=0;i<=d-1;i++)
    {
        scanf("%d",&m[i]);
    }
        if(d==1&&m[0]!=0&&m[0]!=15)
        {
            printf("-1\n");
        }
        else{
        if(d==1&&m[0]==0)
        {
            printf("UP\n");
        }
        if(d==1&&m[0]==15)
        {
            printf("DOWN\n");
        }
        else{if(d!=1&&(m[d-1]==15||m[d-2]==m[d-1]+1)&&m[d-1]!=0)
        {
            printf("DOWN\n");
        }
        else if(d!=1&&(m[d-2]==m[d-1]-1||m[d-1]==0)&&m[d-1]!=15)
        {
            printf("UP\n");
        }}
        }
    return 0;
}
