/*  ���õݹ麯��hn(n,a,b,c)չʾ��n���̴�A׮����B׮�Ƶ�C׮�Ĺ��̣�
    ����mv(a,c)�����A׮��C׮�Ĺ���
    ����hn(n,a,b,c)��
        n=1ʱ����mv(a,c)
        n>1ʱ��������������
        (1) hn(n-1,a,c,b)   (2)mv(a,c)  (3)hn(n-1,b,a,c)
 */

 #include<stdio.h>
 int k=0;
 void mv(char x,char y)
 {
     printf(" %c->%c ",x,y);
     k++;
     if(k%5==0)
        printf("\n");
 }

 void hn(int m,char a,char b,char c)
 {
     if(m==1)   mv(a,c);
     else
     {
         hn(m-1,a,c,b);                 //��һ��
         mv(a,c);                       //�ڶ���
         hn(m-1,b,a,c);                 //������
     }
 }
 void main()
 {
     int n;
     printf("\n input n: ");scanf("%d",&n);
     hn(n,'A','B','C');
     printf("\n k=%d\n",k);
 }
