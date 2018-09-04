#include<iostream>
using namespace std;

struct action{
    int s;              //起始时间
    int f;              //结束时间
    int index;          //活动的编号
};
action a[1000]

bool cmp(const action &a,const action &b)
{
    if(a.f<=b.f)    return true;
    return false;
}

sort(a,a+n+1,cmp);                  //按活动的结束时间升序排序

void GreedySelector(int n,action a[],bool b[])
{
    b[1]=true;                      //第一个活动必选
    int preEnd=1;
    for(int i=2;i<=n;i++)
        if(a[i].s>=a[preEnd].f)         //检查活动i是否与当前已经选择的所有活动相容
        {
            b[i]=true;
            preEnd=i;
        }
}

for(int i=1;i<=n;i++)
    if(b[i])    printf("%d",a[i].index);
printf("\n");
