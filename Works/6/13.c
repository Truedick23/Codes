#include<stdio.h>
int main()
{
    char a[16]={"I am a "};
    char b[9]={"truedick"};
    int j,k;
    for(j=7,k=0;j<15,k<8;j++,k++)
    {
        a[j]=b[k];
    }
    puts(a);
    return 0;
}
