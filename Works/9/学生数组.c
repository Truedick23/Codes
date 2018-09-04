#include<stdio.h>
struct Student
{
    int num;
    char name[20];
    char sex;
    float mark[5];
}Stu[5]={{1602001,"ZhangSan",'M',{130.3,99.5,87,44.3,54.94}},
{1602002,"Trump",'F',{42.3,42.5,123,56.1,23.4}},
{1602003,"Hillary",'M',{98.4,150,150.1,43.6,49.3}},
{1602004,"Obama",'M',{139.0,145.2,150,124.3,123.3}},
{1602005,"Roosevelt",'M',{1.4,45.7,23.1,89.1,150}}};

double aver(int x)
{
    int i=0;
    double sum=0;
    for(i=0;i<5;i++)
    {
        sum+=Stu[x].mark[i];
    }
    return(sum/5);
}

int main()
{
    int i,m,n,s;
    printf("(Please input 0 to exit)\n");
    while(1)
    {
        printf("Please choose one particular student, input his number: ");
        scanf("%d",&n);
        i=n%10;
        if(!n)  {printf("Thank you for using!(^_^)\n");break;}
        while(1)
        {
            printf("What do you want to know about him?\n(Input 0 to change student)\n1-name\n2-sex\n3-mark\n\t:");scanf("%d",&m);
                if(m==1)
                {
                    printf("%s\n",Stu[n-1].name);
                }
                else if(m==2)
                {
                    printf("%c\n",Stu[n-1].sex);
                }
                else if(m==3)
                {
                    printf("Please choose one subject(1~5) or the average(6):");scanf("%d",&s);
                    if(s==6)    printf("The average score is: %.2f\n",aver(n));
                    else
                    printf("The mark of No.%d subject is: %d\n",s,Stu[n-1].mark[s-1]);
                }
                else if(!m)
                {
                    printf("\nConvert to another student! \n");
                    break;
                }
                else printf("Error!");
        }
    }
    return 0;
}
