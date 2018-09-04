#include<iostream>
#include<iomanip>
#include<cstdio>
using namespace std;

int main()
{
    double n,sum=0;
    for(int i=0;i<12;i++)
    {
        cin>>n;
        sum+=n;
    }
    sum/=12.00;
    printf("$%.2f",sum);
}
