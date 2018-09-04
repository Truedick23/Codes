#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    const double pi=3.14;
    int num=1;
    int i,n;
    cin>>n;
    for(int j=0;j<n;j++)
    {
        double x,y,s,o=50;
        cin>>x>>y;
        s=(x*x+y*y)*pi/2;
        for(i=1;o<s;i+=1)
            o+=50;
        cout<<"Property "<<num++<<": This property will begin eroding in year "<<i<<"."<<endl;
    }
    cout<<"END OF OUTPUT."<<endl;
    return 0;
}
