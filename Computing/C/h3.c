#include<stdio.h>

void AddOne()
{
	static int iInt=3;
	iInt=iInt*3*3;
	printf("%d\n",iInt);
}
int main()
{
	printf("µ÷ÓÃ: ");
	AddOne();
	return 0;
}