#include<iostream>
using namespace std;
# define MAXM  10000001

int func(double n)
{
    double a,sum=0.00,i;
    for(i=1;sum<=n;i++)
    {
        a=1.00/(i+1);
        sum+=a;
    }
    return i-1;
}

int main()
{
    double n;
    for(;;){
        cin>>n;
        if(n==0.00) return 0;
        cout<<func(n)<<" card(s)"<<endl;
    }

    return 0;
}
