/*  �����������һ����������r(1),r(2),....,r(n)�У�Ѱ�ҵ�kСԪ�ص������Ϊѡ��
                �ر�ģ���k=n/2ʱ����Ѱ��λ��n��Ԫ���е��м�Ԫ�أ���Ϊ��ֵ����
    ���˼·������4.5.1�ķ�������˼·��
        ��n��������ȡһ������Ϊ��׼������������ݷ�Ϊ��������С�ڻ�׼��������ߣ����ڻ�׼���ұߣ�
        ��׼��λ��s����
        (1)��s=k����׼����Ϊ��Ѱ��ĵ�kСԪ�ء�
        (2)��s>k����֪���С�ڸû�׼���ĸ���s-1>=k��������߼�������
        (2)��s<k����֪��Ѱ��ĵ�kСԪ�����ұ������������ұ߼�������
                ��󲻶��ظ��˹��̣�֪������(1)ʱ��������
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int m1,m2,k,r[20001];
void main()
{
    int i,j,n,t;
    int s(int m1,int m2,int k);
    t=time(0)%1000;srand(t);                //�������������ʼ��
    printf(" Input the number of number that participate: ");scanf("%d",&n);
    printf(" Input the ranking of the number: ");scanf("%d",&k);
    printf(" The numbers are: \n");
    for(i=1;i<=n;i++)
    {
        t=rand()%(4*n)+10;                  //������������n������
        for(j=1;j<i;j++)
            if(t==r[j]) break;
        if(j==i)
        {
            r[i]=t;printf(" %d",r[i]);
        }
        else {i--;continue;}
    }
    s(1,n,k);                       //���õݹ麯��
    printf(" \n The integer among %d that ranked %d is %d. \n",n,k,r[k]);
}
int s(int m1,int m2,int k)
{
    int i,j;
    if(m1<m2)
    {
        i=m1;j=m2;r[0]=r[i];                //�����i����Ϊ������׼
        while(i!=j)
        {
            while(r[j]>=r[0]&&j>i)              //���������������Ƿ���ڻ�׼
                j--;
            if(i<j) {r[i]=r[j];i++;}            //��С�ڻ�׼��һ��������r[j]
            while(r[j]<=r[0]&&j>i)              //���������������Ƿ�С�ڻ�׼
                i++;
            if(i<j) {r[j]=r[i];j--;}            //�Ѵ��ڻ�׼��һ��������r[j]
        }
        r[i]=r[0];                              //�ѻ�׼��ֵ����r[j]
    }
    if(i==k)    return r[k];
        else if(i>k)    return s(m1,i-1,k);
    else return s(i+1,m2,k);
}


