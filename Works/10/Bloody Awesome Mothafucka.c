-#include<stdio.h>
#include<stdlib.h>
struct Student
{
    int num;
    char name[100];
    double scores[3];
    double aver;
}Stu[6];

void Swap(struct Student *a,struct Student *b)
{
    struct Student temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

void Sort(int n)
{
    struct Student *p1,*p2;
    p1=Stu;
    for(;p1-Stu<n-1;p1++)
    {
        p2=Stu+n-1;
        for(;p2-p1>0;p2--)
        {
            if(p1->aver>p2->aver)
                Swap(p1,p2);
        }
    }
}

void Cinque()
{
    struct Student *p=Stu;
    char space;
    double sum=0;
    int i1,i2;
    FILE *fout;
    fout=fopen("stud.txt","w");
    printf("Please input the information of the five students:\n");
    for(i1=0;i1<5;i1++,p++)
    {
        printf("\nNo.%d student:\n",i1+1);
        printf("Name:\t");scanf("%s",p->name);space=getchar();
        printf("Number:\t");scanf("%d",&p->num);
        printf("Scores: \n");
        for(i2=0;i2<3;i2++)
        {
            printf("No.%d subject:\t",i2+1);scanf("%lf",&p->scores[i2]);
            sum+=p->scores[i2];
        }
        p->aver=sum/3;
        sum=0;
    }
    for(p=Stu,i1=0;i1<5;i1++,p++)
    {
        fprintf(fout,"No.%d student:\n",i1+1);
        fprintf(fout,"Name:\t%s\n",p->name);
        fprintf(fout,"Number:\t%d\nScores:\n",p->num);
        for(i2=0;i2<3;i2++)
            fprintf(fout,"No.%d subject: %f\n",i2+1,p->scores[i2]);
        fprintf(fout,"Average score:\t%f\n\n",p->aver);
    }
    return;
}

void Sei()
{
    FILE *fout;
    struct Student *p;
    int i1,i2;
    fout=fopen("stu_sort.txt","w");
    Sort(5);
    for(p=Stu,i1=0;i1<5;i1++,p++)
    {
        fprintf(fout,"No.%d student:\n",i1+1);
        fprintf(fout,"Name:\t%s\n",p->name);
        fprintf(fout,"Number:\t%d\nScores:\n",p->num);
        for(i2=0;i2<3;i2++)
            fprintf(fout,"No.%d subject: %f\n",i2+1,p->scores[i2]);
        fprintf(fout,"Average score:\t%f\n\n",p->aver);
    }
}

void Sette()
{
    FILE *fout;
    fout=fopen("stu_resort.txt","w");
    int i;
    double sum=0;
    char space;
    struct Student *p;
    int i1,i2;
    printf("\nPlease input No.6 student's information:\n");
    printf("Name:\t");scanf("%s",Stu[5].name);space=getchar();
    printf("Number:\t");scanf("%d",&Stu[5].num);
    printf("Scores:\n");
    for(i=0;i<3;i++)
    {
        printf("No.%d subject:\t",i+1);scanf("%lf",&Stu[5].scores[i]);
        sum+=Stu[5].scores[i];
    }
    Stu[5].aver=sum/3;
    Sort(6);
    for(p=Stu,i1=0;i1<6;i1++,p++)
    {
        fprintf(fout,"No.%d student:\n",i1+1);
        fprintf(fout,"Name:\t%s\n",p->name);
        fprintf(fout,"Number:\t%d\nScores:\n",p->num);
        for(i2=0;i2<3;i2++)
            fprintf(fout,"No.%d subject: %f\n",i2+1,p->scores[i2]);
        fprintf(fout,"Average score:\t%f\n\n",p->aver);
    }
}

void Otto()
{
    struct Student *p;
    int i1,i2;
    FILE *fout;
    fout=fopen("stu_sort.txt","a");
    fprintf(fout,"\n\n\n\n");
    for(p=Stu,i1=0;i1<6;i1++,p++)
    {
        fprintf(fout,"No.%d student:\n",i1+1);
        fprintf(fout,"Name:\t%s\n",p->name);
        fprintf(fout,"Number:\t%d\nScores:\n",p->num);
        for(i2=0;i2<3;i2++)
            fprintf(fout,"No.%d subject: %f\n",i2+1,p->scores[i2]);
        fprintf(fout,"Average score:\t%f\n\n",p->aver);
    }
}

int main()
{
    Cinque();
    Sei();
    Sette();
    Otto();
    return 0;
}
