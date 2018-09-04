#include<stdio.h>
int main()
{
    int i,t,m[100],n[100],x=0,y=0,j;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        scanf("%d %d",&m[i],&n[i]);
    }
    for(j=0;j<t;j++)
    {
        if(m[j]>n[j])
            x++;
        if(m[j]==n[j]){
            y++;
            x++;}
        if(m[j]<n[j])
            y++;
    }
    if(x>y)
    {
        printf("Mishka\n");
    }
    else{
    if(x<y)
    {
        printf("Chris\n");
    }
    if(x==y)
    {
        printf("Friendship is magic!^^\n");
    }}
    return 0;
}
