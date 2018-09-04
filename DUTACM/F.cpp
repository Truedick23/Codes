#include<iostream>
#include<algorithm>
using namespace std;
bool cmp(int a,int b)
{
    return a<b;
}
int main()
{
    int a[10000],n,q,i,b,c,d;
    cin>>n>>q;
    for(i=1;i<=n;i++)
        cin>>a[i];
    for(i=0;i<q;i++)
        {
            int k=1,l[10000],p;
            cin>>b>>c;
            for(p=b;p<=c;p++)
            {
                l[p]=a[p];
            }
            sort(l+b,l+c,cmp);
            d=l[b+1]-l[b];
            for(p=b+1;p<=c;p++)
                if(l[p]-l[p-1]!=d)
                    {
                        k=0;break;
                    }
            if(k) cout<<"YES"<<endl;
            else if(!k) cout<<"NO"<<endl;
        }
        return 0;
}
