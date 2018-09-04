#include<stdio.h>
int main()
{
	int a,b,c,sum;
	scanf("%d%d%d",&a,&b,&c);
	if (a<b)
	{
		if (c<a)
			sum=a+b;
		else if (c>b)
			sum=b+c;
		else
			sum=b+c;
	}
	else if (a>b)
	{
		if (c>a)
			sum=c+a;
		else if (c<b)
			sum=a+b;
		else
			sum=c+a;
	}
	else
		sum=a+c;
	printf("%d",sum);
	return 0;
}
			