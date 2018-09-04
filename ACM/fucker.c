#include<stdio.h>
#include<math.h>
int main()
{
    double lower(double x,double y);
	double x1,x2,y1,y2,dd,d,s;
    while(~scanf("%f%f%f%f",&x1,&x2,&y1,&y2))
    {
        dd=(x1-y1)*(x1-y1)+(x2-y2)*(x2-y2);
        s=lower(dd,d);
        printf("%.2f\n",s);
    }
   return 0;
}

double lower(double x,double y)
{
	y=sqrt(x);
	return y;
}
