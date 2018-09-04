#include<stdio.h>
#define PI 3.1415
int main()
{
    float r,h,c,s,ss,v,vv;
    printf("请赋值\nr=");
    scanf("%f",&r);
    printf("h=");
    scanf("%f",&h);
    c=2*PI*r;
    s=PI*r*r;
    ss=4*PI*r*r;
    v=4/3*PI*r*r*r;
    vv=PI*r*r*h;
    printf("圆周长=%.2f\n圆面积=%.2f\n圆球表面积=%.2f\n圆球面积=%.2f\n圆柱体积=%.2f\n",c,s,ss,v,vv);
    return 0;
}
