#include<iostream>
using namespace std;
#include<algorithm>
#include<cmath>

int getSeq(int n) {
    int a[10],d=0,result=0,i=0;
    while(n>10) {
        a[d]=n%10;
        n-=a[d];
        n/=10;
        d++;
    }
    a[d]=n;
    if(d>0)
        sort(a,a+d);
    while(i<=d) {
        result+=pow(10,i)*a[i];
        i++;
    }
    return result;
}

int Oper(int n)
{
    int res=1;
    for(int i=2;i<=n;i++) {
        res=getSeq(2*res);
    }
    return res;
}

int main()  {
    int n,i,num,func;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>num;
        cout<<Oper(num)<<endl;
    }
    return 0;
}
