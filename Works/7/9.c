#include<stdio.h>
#include<string.h>
void cat(char x[],int l)
{
    int i,a=0,b=0,c=0;
    for(i=0;i<l;i++)
    {
        if(x[i]>='a'&&x[i]<='z'||x[i]>='A'&&x[i]<='Z')  a++;
        if(x[i]>='0'&&x[i]<='9')    b++;
        if(x[i]==32)    c++;

    }
    printf("The number of characters are: %d\nThe number of numbers are: %d\nThe number of spaces are: %d\n",a,b,c);
}

int main()
{
    char a[100];
    gets(a);
    int l=strlen(a);
    cat(a,l);
    return 0;
}
