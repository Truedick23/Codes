#include<stdio.h>
#include<string.h>
#define MAXN 10000
/*void input(char *x[])
{
    int i;
    for(i=0;i<10;i++)
    {
        scanf("%s",x+i);
    }
}*/

/*void swap(char *a,char *b)
{
    char *t;
    t=a;
    a=b;
    b=t;
}*/

void sort(char *x[])
{
    int i1,i2;
    char *t;
    for(i1=1;i1<10;i1++)
    for(i2=9;i2>=i1;i2--)
    {
        if(strcmp(x[i2],x[i2-1])>0)   {t=x[i2];x[i2]=x[i2-1];x[i2-1]=t;};
    }
}

void output(char *x[])
{
    int i;
    for(i=0;i<10;i++)
    {
        printf("%s\n",*(x+i));
    }
}

int main()
{
    char *c[10]={"dawdawd","grgrg","wqeqwd","Casewe","9grgrg","5243","weqweqwe","nfgnfn","eqwe","FEFW"};
    output(c);
    printf("\n");
    sort(c);
    output(c);
    return 0;
}

