#include<iostream>
using namespace std;

struct action{
    int s;              //��ʼʱ��
    int f;              //����ʱ��
    int index;          //��ı��
};
action a[1000]

bool cmp(const action &a,const action &b)
{
    if(a.f<=b.f)    return true;
    return false;
}

sort(a,a+n+1,cmp);                  //����Ľ���ʱ����������

void GreedySelector(int n,action a[],bool b[])
{
    b[1]=true;                      //��һ�����ѡ
    int preEnd=1;
    for(int i=2;i<=n;i++)
        if(a[i].s>=a[preEnd].f)         //���i�Ƿ��뵱ǰ�Ѿ�ѡ������л����
        {
            b[i]=true;
            preEnd=i;
        }
}

for(int i=1;i<=n;i++)
    if(b[i])    printf("%d",a[i].index);
printf("\n");
