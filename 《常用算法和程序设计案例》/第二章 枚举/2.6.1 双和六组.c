/*����ż��2n�ֽ�Ϊ6��������ȵ�������a,b,c,d,e,f,�ֳ�������Ԫ�飨Լ��a<b<c,d<e<f,a<d��������������Ԫ������������ԣ�
    a+b+c=d+e+f        1/a+1/b+1/c=1/d+1/e+1/f
    �����Ԫ�飨a,b,c���루d,e,f����Ϊ����n��˫�Ͷ���*/

#include<stdio.h>
#include<math.h>
void main()
{
    int a,b,c,d,e,f,x,n;
    scanf("%d",&n);
    x=0;
    for(a=1;a<=(n-3)/3;a++)                     //��b���ٱ�a��1��c���ٱ�a��2
        for(b=a+1;b<=(n-a-1)/2;b++)                 //��c��b���ٴ�1
            for(d=a+1;d<=(n-3)/3;d++)                   //��d���ٱ�a��1
                for(e=d+1;e<=(n-d-1)/2;e++)
    {
        c=n-a-b;f=n-d-e;                                //ȷ����������
        if(a*b*c*(e*f+f*d+d*e)!=d*e*f*(b*c+c*a+a*b))
            continue;                                    //�ų������Ͳ����
        x++;
        printf("%d:(%3d,%3d,%3d),",x,a,b,c);                //ͳ�Ʋ����˫�Ͷ���
        printf("(%3d,%3d,%3d);\n",d,e,f);
    }
    if(x>0) printf("There are(is) %d solutions in total!\n",x);
    else printf("Not a solution!\n");
}
