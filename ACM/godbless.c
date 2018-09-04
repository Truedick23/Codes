#include<stdio.h>
#include<math.h>
int main()
{
	double dd,d,s;
	float x1,y1,x2,y2;
    while(scanf("%f %f %f %f",&x1,&y1,&x2,&y2)!=EOF)
    {
        dd=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
        d=sqrt(dd);
        printf("%.2f\n",d);
    }
   return 0;
}

