#include<iostream>
using namespace std;
#define MAXM 10001

int main()
{
    int time=0;
    while(1)
    {
        int p,e,i,d,result,j,k,tem;
        cin>>p>>e>>i>>d;
        if(p==-1&&e==-1&&i==-1&&d==-1)  break;
        for(j=d;j<=30000;j++)
            if(j&&(j-p)%23==0&&(j-e)%28==0&&(j-i)%33==0)   break;
        cout<<"Case "<<++time<<": the next triple peak occurs in "<<j-d<<" days."<<endl;
    }
}
