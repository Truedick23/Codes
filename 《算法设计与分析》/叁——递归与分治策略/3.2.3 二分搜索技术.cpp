/*  ���������㷨�Ļ���˼���ǽ�n��Ԫ�طֳɸ���������ͬ�����룬ȡa[n/2]��x���Ƚϡ�
    ���x=a[n/2]�����ҵ�x���㷨��ֹ��
    ���x<a[n/2]����ֻҪ������a����벿�ּ�������x��
    ���x>a[n/2]����ֻҪ������a���Ұ벿�ּ�������x��   */
#include<iostream>
using namespace std;
int BinarySearch(int a[],int x,int n)
{
    int left=0;
    int right=n-1;
    while(left<=right)
    {
        int middle=(left+right)/2;
        if(x==a[middle])    return middle;
        if(x>a[middle]) left=middle+1;
        else right=middle-1;
    }
    return -1;
}

int main()
{
    int a[10000],n,x,r;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    cin>>x;
    r=BinarySearch(a,x,n);
    if(r==-1)   cout<<"Not found!"<<endl;
    else cout<<r<<endl;
}

