#include<iostream>
using namespace std;
int main()
{
    int i,n,a[100000],t,l,k=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    sort(a,a+n);
    for(i=0;i<n;i++)
        if(a[i]==a[0]||a[i]==a[n-1])  k++;
    printf("%d\n",n-k);
    return 0;
}
