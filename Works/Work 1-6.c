#include<stdio.h>
int main()
{
	int max(int x,int y,int z);
	int iA,iB,iC,iMax;
	scanf("%d,%d,%d",&iA,&iB,&iC);
	iMax=max(iA,iB,iC);
	printf("the maximum number is %d\n",iMax);
	return 0;
}

int max(int x,int y,int z)
{
	int m;
	if(x>y)
	{
		if(x>z)
		m=x;
		else m=z;
	}
	else
	{
		if(z>y)
		m=z;
		else
		m=y;
	}
	return(m);
}

	

