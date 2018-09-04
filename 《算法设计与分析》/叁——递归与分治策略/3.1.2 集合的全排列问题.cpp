/*  设 R ={r1,r2,……,rn}是要进行排列的n个元素，显然一共有n！种排列。令Ri=R-{ri}。集合X中元素的全排列记为Perms(X)。
    R的全排列可归纳定义如下：
        当n=1时，Perm(R)=(r)，其中r是集合R中唯一的元素；
        当n>1时，Perm(R)由(r1)Perm(R1),(r2)Perm(R2),...,(rn)Perm(Rn)构成。

        一般情况下，k<m。该算法将list[k:m]中的每一个元素分别与list[k]中的元素交换，然后递归地计算元素list[k+1:m]的全排列，
    并将计算结果作为list[0:k]的后缀。*/

#include<iostream>
using namespace std;
void Perm(int list[],int k,int m)
{
    if(k==m)
    {
        for(int i=0;i<=m;i++)
            cout<<list[i]<<" ";
        cout<<endl;
    }
    else
        for(int j=k;j<=m;j++)
        {
            swap(list[k],list[j]);
            Perm(list,k+1,m);
            swap(list[k],list[j]);
        }
}

int main()
{
    int list[10000],n,k,m;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>list[i];
    }
    cin>>k;cin>>m;
    Perm(list,k,m);
    return 0;
}

