#include<stdio.h>
#include<string.h>
int main()
{
    int m,n;
    scanf("%d",&n);

    m=n;
        for(m=n;m>0;m--)
        {
            int i,num=0;
            char str[101];
            scanf("%s",str);
            for(i=strlen(str);i>0;i--)
            {
                if(str[i]>='0'&&str[i]<='9')
                {
                    num++;
                }
            }
            printf("%d\n",num);
        }


    return 0;
}
