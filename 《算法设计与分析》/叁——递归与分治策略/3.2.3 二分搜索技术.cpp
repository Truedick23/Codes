/*  二分搜索算法的基本思想是将n个元素分成个数大致相同的两半，取a[n/2]与x作比较。
    如果x=a[n/2]，则找到x，算法终止。
    如果x<a[n/2]，则只要在数组a的左半部分继续搜索x。
    如果x>a[n/2]，则只要在数组a的右半部分继续搜索x。   */
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

