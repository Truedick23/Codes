/*���������÷�ȫ�����������ɵ��Ҹ��С����������Խ���֮�;���ȵķ��󣬴ӹ涨������Ѱ�ҾŸ�����������һ�����������÷�
        ��  n-x  n+w n-y
            n+z  n   n-z
            n+y  n-w n+x            �跽���м���Ϊn��ÿ��ÿ��ÿ�Խ���֮��Ϊs��ע�⵽:
                                    ���м�һ�У�+���м�һ�У�+�����Խ��ߣ�=4s
                                    �������оŸ���֮��=3s            �ʵõ�n=s/3

            Ϊ�����ظ���Լ�����Խ��ߵ�3����Ϊ�������£�x>0,y>0��������һ�д������ң�x>y��
            ��������ʱ   z=x-y, w=x+y (x>y)      ͬʱ��֪9�������в�����ż����2�����x,y,z,w��ֻ������ż��*/

#include<stdio.h>
#include<math.h>
int main()
{
    int c,d,j,k,n,t,t1,t2,w,x,y,z,m;
    int a[3000];
    m=0;
    printf("Input the range:");scanf("%d%d",&c,&d);
    if(c%2==0)  c=c+1;      //�Թ�ż��
    if(c<3)  c=3;
    for(k=c;k<=d;k++)   a[k]=0;
    for(k=c;k<=d;k+=2)
    {
        for(t=0,j=3;j<=sqrt(k);j+=2)
        if(k%j==0) {t=1;break;}             //�о���������kΪ��������ֵa[k]=1
        if(t==0)    a[k]=1;
    }
    for(n=c;n<=d-8;n=n+2)
    {
        if(a[n]==0) continue;               //�ų�������Ϊ������
        for(y=2;y<=n-3;y+=2)
        for(x=y+2;x<=n-1;x+=2)
        {
            z=x-y;w=x+y;
            if(x==2*y||n-w<c||n+w>d)        //x=2yʱ������z=y��������ͬ������������n-w��n+w�ֱ�Ϊ������Сֵ�����豣֤���������ڷ�Χ֮��
                continue;
            t1=a[n-w]*a[n+w]*a[n-z]*a[n+z];
            t2=a[n-x]*a[n+x]*a[n-y]*a[n+y];
            if(t1*t2==0)    continue;               //������������Ϊ����
            m++;
            printf("  NO%d:\n",m);
            printf("%5d%5d%5d\n",n-x,n+w,n-y);
            printf("%5d%5d%5d\n",n+z,n,n-z);
            printf("%5d%5d%5d\n",n+y,n-w,n+x);
        }
    }
    printf(" The are %d solution in total. \n",m);
}
