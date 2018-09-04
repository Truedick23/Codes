#include<stdio.h>
#include<stdlib.h>
struct Student
{
    int num;
    char name[100];
    float score[3];
}stu[5]={{1,"daewd",{34,234,23}},{2,"fef",{53,123,32}},{3,"grgr",{34,56,76}},{4,"bccx",{98,23,12}},{5,"fvcv",{887,34,23}}};

float Ave[5];

void Input()
{
    struct Student *p;
    p=stu;
    float *pp,sum;
    int i,n;
    char space;
    printf("Please input the informations:\n");
    for(i=1;i<=5;i++,p++)
    {
        sum=0;
        printf("\nNo.%d student:\n",i);
        printf("Number: ");scanf("%d",&p->num);//space=getchar();
        printf("Name: ");scanf("%s",p->name);
        printf("Scores: \n");
        for(pp=p->score,n=0;n<3;n++,pp++)
        {
            printf("No.%d subject: ",n+1);scanf("%f",pp);
            sum+=(*pp);
        }
        Ave[i-1]=sum/3;
    }
    return;
}

void Store()
{
    FILE *f1;
    int i,t;
    struct Student *p;
    p=stu;
    if((f1=fopen("D:\\Files\\stud.dat","w"))==NULL)
        {printf("Error opening!!\n");exit(0);}
    for(i=0;i<5;i++,p++)
    {
        printf("No.%d Student:\nNumber: %f\nName: %s\nScores:\n",i+1,p->num,p->name);
        for(t=0;t<3;t++)
            printf("No.%d subject: %f",t+1,p->score[t]);
        fprintf(f1,"No.%d Student:\nNumber: %f\nName: %s\nScores:\t%f\t%f\t%f\nAverage score: %f\n",i+1,p->num,p->name,p->score[0],p->score[1],p->score[2],Ave[i]);
    }
    fclose(f1);
    return;
}

int main()
{
    //Input();
    Store();
    return 0;
}
