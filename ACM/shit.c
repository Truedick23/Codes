#include<stdio.h>
#include <math.h>
int main()
{
    int x1,x2,y1,y2;
    double d;
    while(~scanf("%d%d%d%d",&x1,&x2,&y1,&y2)){
        d=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
        printf("%.2f",d);
    }
    return 0;
}
