/*������3n�ֽ��9��������ͬ��������a,b,c,d,e,f,g,h,i�����㣺
    a+b+c=d+e+f=g+h+i
    a*b*c=d*e*f=g*h*i   ��Լ��a<b<c,d<e<f,g<h<i,a<d<g��
��a,b,c������d,e,f������g,h,i����Ϊ����n�ĺͻ�����*/

#include<stdio.h>
void main()
{
    int a,b,c,d,e,f,g,h,i,j,x,n;long t;
    printf("Input n:");scanf("%d",&n);
    x=0;
    for(a=1;a<=(n-3)/3;a++)                     //ͬ��һ�⣬��a,b,c�Ĵ�С��ϵ�ó�
    for(b=a+1;b<=(n-a-1)/2;b++)
    for(d=a+1;d<=(n-3)/3;d++)                   //d,eͬ��
    for(e=d+1;e<=(n-d-1)/2;e++)
    for(g=d+1;g<=(n-3)/3;g++)                   //g,h
        for(h=g+1;h<=(n-g-1)/2;h++)
    {
        c=n-a-b;f=n-d-e;i=n-g-h;                //��֤��������
        t=a*b*c;
        if(d*e*f==t&&g*h*i==t)                  //�ų��������
        {
            x++;
            printf("  %d: %3d %3d %3d; ",x,a,b,c);
            printf("%3d %3d %3d; ",d,e,f);
            printf("%3d %3d %3d; (%ld)\n",g,h,i,t);
        }
    }
    if(x>0) printf(" There are %d solutions in total! \n",x);
    else printf("No solution!\n");
}
