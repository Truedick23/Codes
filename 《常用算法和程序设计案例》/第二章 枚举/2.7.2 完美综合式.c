/*"完美"是指各个数字出现且不重复，“综合”是指包含有加、减、乘、除和乘方运算
        把数字1~9填入以下九个□中，使该式成立：
        □^□+□□÷□-□□□×□=0
        且规定1不能作为一位数出现*/

#include<stdio.h>
#include<math.h>
void main()
{
    double a,b,c,d,e,z;
    int j,k,t,n,f[10];
    printf(" □^□+□□/□-□□□×□=0 \n");
    n=0;
    for(a=2;a<=9;a++)
    for(b=2;b<=9;b++)
    for(c=2;c<=9;c++)
    for(z=2*c;z<=98;z=z+c)                      //确保z为c的倍数
    for(d=102;d<=987;d++)
    for(e=2;e<=9;e++)
    {
        if(z<10||pow(a,b)+z/c!=d*e) continue;           //检验等式是否成立
        t=0;
        f[0]=0;f[1]=a;f[2]=b;f[3]=c;f[4]=e;             //9个数字赋给数组
        f[5]=floor(z/10);f[6]=fmod(z,10);
        f[7]=floor(d/100);f[8]=fmod(d,10);
        f[9]=floor(fmod(d,100)/10);
        for(k=0;k<=8;k++)
            for(j=k+1;j<=9;j++)
                if(f[k]==f[j])                          //检验重复
                {
                    t=1;break;
                }
        if(t==0)                                        //输出一个解
        {
            n++;
            printf("%2d:%.0f^%.0f+%.0f/%.0f",n,a,b,z,c);
            printf("-%.0f*%.0f=0 \n",d,e);
        }
    }
}
