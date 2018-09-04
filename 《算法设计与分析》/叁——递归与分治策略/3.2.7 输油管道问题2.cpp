//采用分治策略求中位数

#include<iostream>
#include<math.h>
using namespace std;

int main()
{
    int n;
    int x;
    int a[1000];
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>x>>a[i];
    int y=select(0,n-1,n/2);
    int min=0;
    for(int i=0;i<n;i++)
        min+=(int)fabs(a[i]-y);
    cout<<min<<endl;
}
