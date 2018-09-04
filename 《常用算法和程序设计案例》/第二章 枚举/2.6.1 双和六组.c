/*给定偶数2n分解为6个互不相等的正整数a,b,c,d,e,f,分成两个三元组（约定a<b<c,d<e<f,a<d），若这两个三元组具有以下特性：
    a+b+c=d+e+f        1/a+1/b+1/c=1/d+1/e+1/f
    则把三元组（a,b,c）与（d,e,f）称为基于n的双和二组*/

#include<stdio.h>
#include<math.h>
void main()
{
    int a,b,c,d,e,f,x,n;
    scanf("%d",&n);
    x=0;
    for(a=1;a<=(n-3)/3;a++)                     //因b至少比a大1，c至少比a大2
        for(b=a+1;b<=(n-a-1)/2;b++)                 //因c比b至少大1
            for(d=a+1;d<=(n-3)/3;d++)                   //因d至少比a大1
                for(e=d+1;e<=(n-d-1)/2;e++)
    {
        c=n-a-b;f=n-d-e;                                //确保两组和相等
        if(a*b*c*(e*f+f*d+d*e)!=d*e*f*(b*c+c*a+a*b))
            continue;                                    //排除倒数和不相等
        x++;
        printf("%d:(%3d,%3d,%3d),",x,a,b,c);                //统计并输出双和二组
        printf("(%3d,%3d,%3d);\n",d,e,f);
    }
    if(x>0) printf("There are(is) %d solutions in total!\n",x);
    else printf("Not a solution!\n");
}
