/*������a��С���䱾�������֮��Ϊs������ p(a)=s/a Ϊ�����������ȣ��������ֵ*/

#include<stdio.h>
#include<math.h>
void main()
{
    double a,s,a1,s1,b,k,t,x,y,max=0;
    printf("Input x and y:");
    scanf("%lf%lf",&x,&y);
    for(a=x;a<=y;a++)                       //ö����������������
    {
        s=1;b=sqrt(a);
        for(k=2;k<=b;k++)                   //����Ѱ��a������k
            if(fmod(a,k)==0)
                s=s+k+a/k;                  //�������
        if(a==b*b)  s=s-b;                  //��a=b^2��ȥ���ظ�����b
        t=s/a;
        if(max<t)
        {
            max=t;a1=a;s1=s;
        }
    }
    printf("The maximum sum of integer %.0f is: %.4f\n",a1,max);
    printf("    %.0f have the sum of:\n",a1);
    printf("    %.0f=1",s1);
    for(k=2;k<=a1/2;k++)
        if(fmod(a1,k)==0)
        printf("+%.0f",k);
}

