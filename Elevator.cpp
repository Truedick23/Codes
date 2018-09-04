#include<iostream>
using namespace std;

int main()
{
    int n,f[1000],result=0,ded,i;
    while(cin>>n)
    {
        if(!n)  break;
        for(i=0;i<n;i++)
            cin>>f[i];
        result+=f[0]*6;
        for(i=0;i<n-1;i++)
        {
            ded=f[i+1]-f[i];
            if(ded>0)   result+=ded*6;
            else result-=ded*4;
            result+=5;
        }
        result+=5;
        cout<<result<<"(6*"<<f[0]<<"+5";
        for(i=0;i<n-1;i++)
        {
            ded=f[i+1]-f[i];
            if(ded>0)
                cout<<"+6*"<<ded;
            else
                cout<<"+4*"<<-ded;
            cout<<"+5";
        }
        cout<<")"<<endl;
    }
    return 0;
}
