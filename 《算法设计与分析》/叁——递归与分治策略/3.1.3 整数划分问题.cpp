/*  ��������е�������s������m�����������n��һ��m���֣��������Ϊf(n,m)��������ת��Ϊ��f(n,n)��
    ����f(n,m)�ĵݹ��ϵ���£�
    1. f(1, m)=1, m>=1
    2. f(n, 1)=1, n>=1
    3. f(n, m)=f(n, n), m>=n
    4. f(n, n)=1+f(n, n-1)
    5. f(n, m)=f(n, m-1)+f(n-m, m), n>m>1 */
#include<iostream>
using namespace std;
int split(int n,int m)
{
    if(n==1||m==1)  return 1;
    else if(n<m)    return split(n,n);
    else if(n==m)   return split(n,n-1)+1;
    else return split(n,m-1)+split(n-m,m);
}

int main()
{
    int n;
    cin>>n;
    cout<<split(n,n);
}
