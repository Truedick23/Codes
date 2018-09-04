/*  LCS�������ӽṹ���ʣ�
    ������X={x1,x2,...,xm}��Y={y1,y2,...,yn}��һ�������������Z={z1,z2,..,zk}����
    (1)��xm=yn����zk=xm=yn����Zk-1��Xm-1��Yn-1������������У�
    (2)��xm!=yn����zk!=xm����Z��X(m-1)��Y�������������
    (3)��xm!=yn����zk!=yn����Z��X��Y(n-1)�������������

    �ݹ鷽����
    (1)��xm=ynʱ���ҳ�X(m-1)��Y(n-1)������������У�Ȼ������β������xm(=yn)�ɵ����������������
    (2)��xm!=ynʱ���ҳ�X(m-1)��Y��һ������������м�X��Y(n-1)��һ������������У����нϳ���Ϊ���������������
    */

#define NUM 100
int c[NUM][NUM];                 //���ڼ�¼����������еĳ���
int b[NUM][NUM];                //��������b[i][j]���ڼ�¼��c[i][j]��ֵ������һ��������Ľ�õ���
void LCSLength(int m,int n,const char x[],char y[])
{
    int i,j;
    for(i=1;i<=m;i++)   c[i][0]=0;
    for(i=1;i<=n;i++)   c[0][i]=0;

    for(i=1;i<=m;i++)
    for(j=1;j<=n;j++)
    {
        if(x[i]==y[j])
        {
            c[i][j]=c[i-1][j-1]+1;
            b[i][j]=1;
        }
        else if(c[i-1][j]>=c[i][j-1])
        {
            c[i][j]=c[i-1][j];
            b[i][j]=2;
        }
        else
        {
            c[i][j]=c[i][j-1];
            b[i][j]=3;
        }
    }
}

void LCS(int i,int j,char x[])
{
    if(i==0||j==0)  return;
    if(b[i][j]==1)  {LCS(i-1,j-1,x);printf("%c",x[i]);}
    else if(b[i][j]==2) LCS(i-1,j,x);
    else LCS(i,j-1,x);
}
