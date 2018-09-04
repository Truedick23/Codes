#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

struct DNA{
    char seq[50];
    int inve;
};

bool cmp(DNA a,DNA b)
{
    return a.inve<b.inve;
}

int main()
{
    int inve[100];
    int n,l,len;
    DNA dna[100];
    memset(dna,0,sizeof(dna));
    cin>>len>>n;
    for(int i=0;i<n;i++)
        cin>>dna[i].seq;
    for(int i=0;i<n;i++)
        for(int j=0;j<len-1;j++)
            for(int k=j+1;k<len;k++)
            if(dna[i].seq[j]>dna[i].seq[k]) dna[i].inve++;
    sort(dna,dna+n,cmp);
    for(int i=0;i<n;i++)
        cout<<dna[i].seq<<endl;
    return 0;
}
