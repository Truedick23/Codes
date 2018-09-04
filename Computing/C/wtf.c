#include<stdio.h>

int main()
{
	float MonthlyWage;
	float BasicWage;
	float More;
	int Number;

	puts("Please enter your basic monthly wage:");
	scanf("%f",&MonthlyWage);
	puts("Please enter your selling number:");
	scanf("%d",&Number);

	More=Number*1.5;
	MonthlyWage=BasicWage+More;
	
	puts("Your total monthly wage is:");
	printf("%f\n",MonthlyWage);
	return 0;
}
