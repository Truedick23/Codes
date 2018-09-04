#include<stdio.h>
#include<string.h>
int main()
{
    int n,i,m;
    double t;
    char str[20];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%s %lf",str,&t);
        m=strlen(str);
        if(str[0]=='f')
        {
            if(t<=23.50)
                printf("Master Class\n");
            if(t>23.50&&t<=24.50)
                printf("First Class\n");
            if(t>24.50&&t<=27.50)
                printf("Second Class\n");
            if(t>27.50&&t<=34.50)
                printf("Third Class\n");
            if(t>34.50)
                printf("Oops!\n");
        }
        if(m==9&&str[0]=='b')
        {
            if(t<=25.67)
                printf("Master Class\n");
            if(t>25.67&&t<=27.00)
                printf("First Class\n");
            if(t>27.00&&t<=32.50)
                printf("Second Class\n");
            if(t>32.50&&t<=41.50)
                printf("Third Class\n");
            if(t>41.50)
                printf("Oops!\n");
        }
        if(m==12)
        {
            if(t<=29.70)
                printf("Master Class\n");
            if(t>29.70&&t<=32.50)
                printf("First Class\n");
            if(t>32.50&&t<=37.00)
                printf("Second Class\n");
            if(t>37.00&&t<=44.00)
                printf("Third Class\n");
            if(t>44.00)
                printf("Oops!\n");
        }
        if(m==10)
        {
            if(t<=28.03)
                printf("Master Class\n");
            if(t>28.03&&t<=30.50)
                printf("First Class\n");
            if(t>30.50&&t<=35.50)
                printf("Second Class\n");
            if(t>35.50&&t<=43.00)
                printf("Third Class\n");
            if(t>43.00)
                printf("Oops!\n");
        }
    }
    return 0;
}
