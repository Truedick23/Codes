/*  �� R ={r1,r2,����,rn}��Ҫ�������е�n��Ԫ�أ���Ȼһ����n�������С���Ri=R-{ri}������X��Ԫ�ص�ȫ���м�ΪPerms(X)��
    R��ȫ���пɹ��ɶ������£�
        ��n=1ʱ��Perm(R)=(r)������r�Ǽ���R��Ψһ��Ԫ�أ�
        ��n>1ʱ��Perm(R)��(r1)Perm(R1),(r2)Perm(R2),...,(rn)Perm(Rn)���ɡ�

        һ������£�k<m�����㷨��list[k:m]�е�ÿһ��Ԫ�طֱ���list[k]�е�Ԫ�ؽ�����Ȼ��ݹ�ؼ���Ԫ��list[k+1:m]��ȫ���У�
    ������������Ϊlist[0:k]�ĺ�׺��*/

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

