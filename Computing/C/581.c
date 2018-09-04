#include<stdio.h>

int main()
{
	char cBig;
	char cSmall;

	puts("Enter capital character:");
	cBig=getchar();
	cSmall=cBig+32;
	puts("Minuscule character is:");
	printf("%c\n",cSmall);
	return 0;
}
