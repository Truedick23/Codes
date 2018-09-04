#include<iostream>
using namespace std;

int Base(int m,int n)
{
    int t;
    t=m*n;
    while(t>=10)   t=t%10+t/10;
    return t;
}

void PrintStar(int m,int a[][10])
{
    int i1,i2;
    char b[10][10];
    for(i1=1;i1<10;i1++)
        for(i2=1;i2<10;i2++)
        {
            if(a[i1][i2]==m)    b[i1][i2]='*';
            else b[i1][i2]='\0';
        }
    cout<<"\t";
    for(i1=1;i1<=9;i1++)
        cout<<i1<<"\t";
    cout<<endl<<endl;
    for(i1=1;i1<=9;i1++)
        {
            cout<<i1<<"\t";
            for(i2=1;i2<=9;i2++)
            {
                cout<<b[i1][i2]<<"\t";
            }
            cout<<endl<<endl;
        }
}

void print(int a[])
{
    int i1,i2;
    cout<<"\t";
    for(i1=1;i1<=9;i1++)
        cout<<i1<<"\t";
    cout<<endl<<endl;
    for(i1=1;i1<=9;i1++)
        {
            cout<<i1<<"\t";
            for(i2=1;i2<=9;i2++)
            {
                cout<<Base(i1,i2)<<"\t";
            }
            cout<<endl<<endl;
        }
}
int main()
{
    int a[10][10],i1,i2,k,m;
    for(i1=1;i1<10;i1++)
        for(i2=1;i2<10;i2++)
        a[i1][i2]=Base(i1,i2);
    cout<<"Choose your action"<<endl<<endl;
    cout<<"Print the whole spreadsheet---1"<<endl;
    cout<<"Staralize some number----2"<<endl;
    cin>>k;
    if(k==1)
    {
        cout<<"\t";
        for(i1=1;i1<=9;i1++)
            cout<<i1<<"\t";
        cout<<endl<<endl;
        for(i1=1;i1<=9;i1++)
            {
                cout<<i1<<"\t";
                for(i2=1;i2<=9;i2++)
                {
                    cout<<Base(i1,i2)<<"\t";
                }
                cout<<endl<<endl;
            }
    }
    if(k==2)
    {
        cin>>m;
        PrintStar(m,a);
    }
    return 0;
}
