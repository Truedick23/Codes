
#include<iostream>
#include<algorithm>
#include<iomanip>

using namespace std;
void Clear(double a[])
{
    int i;
    for(i=0;i<100000;i++)
        a[i]=0;
}
void RemoveDuplates(double A[], int nCnt)
{
    int j=1;
    for (int i=1,j=1;i<nCnt&&j<nCnt; i++)
    {
        while(j<nCnt&& A[i] == A[j])
            j++;
        if( j > i + 1 && j < nCnt)
            A[i + 1] = A[j];
    }
}
bool cmp(double a,double b)
{
    return a>b;
}
int main()
{
    int k,i,a,b,r,t,u;
    double p[100000],m[100000],n[100000];
    cin>>k;
    for(i=0;i<k;i++)
    {
        Clear(m);
        Clear(n);
        cin>>a>>b>>r;
        for(t=1;t<=a;t++)
            cin>>m[t];
        for(t=1;t<=b;t++)
            cin>>n[t];
        for(t=1;t<=a;t++)
            for(u=1;u<=b;u++)
            p[(t-1)*b+u]=m[t]/n[u];
        sort(p,p+a*b,cmp);
        RemoveDuplates(p,a*b);
        cout<<fixed<<setprecision(2)<<p[k]<<endl;
    }
    return 0;
}
