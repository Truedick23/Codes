/*  ���������ֳ�Ϊ�����������������˼���Ƿ��Σ����ֶ���֮��
    �ڴ������n������r[1,2,...,n]����ȡһ����������r[1]����Ϊ��׼��������n-1�����ݷ�Ϊ��������
    С�ڻ�׼����������ߣ����ڻ�׼���������ұߡ�
    �����γ��������������ݵ��������У�Ȼ������������зֱ��ظ��������̣�ֱ������Ԫ���ŵ�λ
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int r[20001];
void main()
{
    int i,n,t;
    void qk(int m1,int m2);
    t=time(0)%1000;srand(t);                    //�������������ʼ��
    printf(" Input n:");scanf("%d",&n);
    printf("The %d integer that participate in are(is): \n",n);
    for(i=1;i<=n;i++)
    {
        r[i]=rand()%(4*n)+10;                   //������������n������
        printf("%5d",r[i]);
    }
    qk(1,n);                                //���õݹ麯��
    printf("\n Sorted: \n",n);
    for(i=1;i<=n;i++)
        printf("%5d",r[i]);
    printf("\n");
}
void qk(int m1,int m2)
{
    int i,j;
    if(m1<m2)
    {
        i=m1;j=m2;r[0]=r[i];                //��r[0]��ʶ��׼������r[i]��Ϊ��׼
        while(i!=j)
        {
            while(r[j]>=r[0]&&j>i)          //���������������Ƿ���ڻ�׼
                j--;
            if(i<j) {r[i]=r[j];i++;}        //������ָ��û�н��棬���С�ڻ�׼���Ǹ���(��r[j])����r[i]��i����һλ
            while(r[j]<=r[0]&&j>i)          //���������������Ƿ�С�ڻ�׼
                i++;
            if(i<j) {r[j]=r[i];j--;}        //ͬ���Ѵ��ڻ�׼����(r[i])����r[j]��j����һλ
        }
        r[i]=r[0];                          //���ѻ�׼������r[i]
        qk(m1,i-1);qk(i+1,m2);              //��i���߼�����������
    }
    return;
}
