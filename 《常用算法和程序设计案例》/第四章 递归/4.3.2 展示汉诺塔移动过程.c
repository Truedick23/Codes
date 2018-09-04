/*  设置递归函数hn(n,a,b,c)展示把n个盘从A桩借助B桩移到C桩的过程，
    函数mv(a,c)输出从A桩到C桩的过程
    对于hn(n,a,b,c)：
        n=1时，即mv(a,c)
        n>1时，分以下三步：
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
         hn(m-1,a,c,b);                 //第一步
         mv(a,c);                       //第二步
         hn(m-1,b,a,c);                 //第三步
     }
 }
 void main()
 {
     int n;
     printf("\n input n: ");scanf("%d",&n);
     hn(n,'A','B','C');
     printf("\n k=%d\n",k);
 }
