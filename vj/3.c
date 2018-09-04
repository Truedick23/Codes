#include<stdio.h>
#include<string.h>
int min(int w,int x,int y,int z)
{
    int m;
    if(x>y)
    {m=y;}
    else
    {m=x;}
    if(m>w)
    {m=w;}
    if(m>z)
    {m=z;}
    return m;
}

int main()
{
    char c[1000];
    int i,h=0,a=0,p=0,pp,y=0,t;
    while(gets(c)!=NULL)
    {
        for(i=0;i<strlen(c);i++)
        {
            h=0;
            a=0;
            p=0;
            y=0;
            switch(c[i])
            {
                case 'h':
                    {
                        h++;
                        break;
                    }
                case 'a':
                    {
                        a++;
                        break;
                    }
                case 'p':
                    {
                        p++;
                        break;
                    }
                case 'y':
                    {
                        y++;
                        break;
                    }
                default:
                {break;}
            }}
        }
        pp=p/2;
        t=min(h,a,pp,y);
        printf("%d\n",t);
    return 0;
}
