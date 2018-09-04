#include<stdio.h>

int main()
{
	float MonthlyWage;
	float BasicWage;
	float More;
	int Number;

	puts("Please enter your basic monthly wage:");
	BasicWage=getchar();
	put("Please enter your selling number:");
	Number=getchar();

	More=Number*1.5;
	MonthlyWage=BasicWage+More;
	
	put("Your total monthly wage is:");
	printf("%f\n",MonthlyWage);
	return 0;
}
