#include<stdio.h>
#include<math.h>

    double x,y;
    float lower(double x,double y)
{
	y=sqrt(x);
	return y;
}
    int main()
{
	double x1,x2,y1,y2,dd,d;
	float s;
    while(scanf("%f %f %f %f",&x1,&x2,&y1,&y2)!=EOF)
    {
        dd=(x1-y1)*(x1-y1)+(x2-y2)*(x2-y2);
        s=lower(dd,d);
        printf("%.2f\n",s);
    }
   return 0;
}

