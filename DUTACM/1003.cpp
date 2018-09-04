#include<iostream>
using namespace std;

int main()
{
    int i,n;
    bool k;
    while(cin>>n)
    {
        for(i=2,k=true;i<=n;i++)
            if(n%i==0)  k=!k;
        if(k)   cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

    return 0;
}
