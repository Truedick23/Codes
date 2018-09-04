//计算矩阵连乘积的递归算法
int Recurve(int i,int j)
{
    if(i==j)    return 0;
    int u=Recurve(i,i)+Recurve(i+1,j)+p[i-1]*p[i]*p[j];
    s[i][j]=i;
    for(int k=i+1;k<j;k++)
    {
        int t=Recurve(i,k)+Recurve(k+1,j)+p[i-1]*p[k]*p[j];
        if(t<u) {u=t;s[i][j]=k};
    }
    m[i][j]=u;
    return u;
}

//计算矩阵连乘积的备忘录算法
int LookupChain(int i,int j)
{
    if(m[i][j]>0)   return m[i][j];
    if(i==j)    return 0;
    int u=LookupChain(i,i)+LookupChain(k+1,j)+p[i-1]*p[i]*p[j];
    s[i][j]=i;
    for(int k=i+1;k<j;k++)
    {
        int t=LookupChain(i,k)+LookupChain(k+1,j)+p[i-1]*p[k]*p[j];
        if(t<u){u=t;s[i][j]=k;}
    }
    m[i][j]=u;
    return u;
}
