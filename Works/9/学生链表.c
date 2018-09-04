#include<stdio.h>
#include<stdlib.h>
#define LEN sizeof(struct Student)

struct Student
{
    int num;
    char name[200];
    char sex;
    float score[5];
    struct Student *next;
};
int n;

struct Student *creat()
{
    //FILE *fin;
    /*fin=fopen("‪‪D://Works//9//input.txt","rb");
    if(fin=NULL) printf("Error Opening!");*/
    int i,t=0;
    struct Student *head;
    struct Student *p1,*p2;
    char space;
    float *p;
    n=1;
    p1=malloc(LEN);
    p2=p1;
    head=p1;
    printf("Name of No.%d student: ",n);scanf("%s",head->name);space=getchar();
    printf("Sex and number: ");scanf("%c%d",&head->sex,&head->num);
    printf("Scores: \n");
    for(p=head->score,i=1;p-head->score<5;p++,i++)
    {
        printf("No.%d subject:",i);scanf("%f",p);
    }
    /*fscanf(fin,"&s%d%c",p1->name,&p1->num,&p1->sex);
    for(i=0;i<5;i++)
    {
        fscanf(fin,"%f",&p1->score[i]);
    }
    space=fgetc(fin);*/
    p2=p1;
    p1->next=malloc(LEN);
    p1=p1->next;
    n++;
    printf("\nName of No.%d student: ",n);
    while(scanf("%s",p1->name)!=EOF)
    {
        space=getchar();
        n++;
        printf("Sex and number: ");scanf("%c%d",&p1->sex,&p1->num);
        printf("Scores: \n");
        for(p=p1->score,i=0;i<5;i++,p++)
        {
            printf("No.%d subject:",i+1);
            scanf("%f",p);
        }
        /*fscanf(fin,"%s%d%c",p1->name,&p1->num,&p1->sex);
        for(i=0;i<5;i++)
        {
            fscanf(fin,"%f",&p1->score[i]);
        }
        space=fgetc(fin);*/
        p2=p1;
        p1->next=malloc(LEN);
        p1=p1->next;
        printf("\nName of No.%d student: ",n);
    }
    space=getchar();
    p1->next=NULL;
    return head;
}
struct Student *Insert(struct Student *head,struct Student *Stu)
{
    struct Student *p1,*p2,*p0;
    p1=head;
    p0=Stu;
    if(head==NULL)
    {
        p1=p0;
        head=p0;
        p0->next=NULL;
    }
    else
    {
        while(p1->next!=NULL&&p1->num<p0->num)
        {
            p2=p1;
            p1->next=p1;
        }
        if(p1->num>p0->num)
        {
            if(p1==head)    {head=p0;head->next=p1;}
            else
            {
                p2->next=p0;
                p0->next=p1;
            }
        }
        else{p2->next=p0;p0->next=NULL;}
    }
    return head;
}

struct Student *Delete(struct Student *head,int num)
{
    struct Student *p0,*p1,*p2;
    p1=p2=head;
    if(p2==NULL)
    {
        printf("Empty! \n");
        return p1;
    }
    while(p1->next!=NULL&&p1->num!=num)
    {
        p2=p1;
        p1=p1->next;
    }
    if(p1->num==num)
    {
        if(head->num==num)
            return(head->next);
        else
        {
            p1=p1->next;
            p2->next=p1;
        }
    }
    else    printf("Not found!");
    return head;
}

struct Student *Output(struct Student *head)
{
    struct Student *p1,*p2;
    p1=head;
    int i,t=1;
    while(p1->next!=NULL)
    {
        printf("\nInformation about No.%d student:\nNumber: %d\nName: %s\nSex: %c\nScores:\n",t++,p1->num,p1->name,p1->sex);
        for(i=0;i<5;i++)
        {
            printf("No.%d subject:%5f\n",i+1,p1->score[i]);
        }
        p1=p1->next;
    }
    return head;
}

int main()
{
    struct Student *head,*Stu;
    int num,i,choices[1000],*p;
    float *pp;
    char none;
    printf("Greetings!\n\n");
    head=creat();
    p=choices;
    printf("\nPlease choose your action:\n1-Insert\n2-Delete\n3-Output\n0-Exit\t");
    while(1)
    {
        scanf("%d",p);
        if(*p!=0)
        {
            if(*p==1)
            {
                printf("\nPlease input that student's information:\n");
                Stu=malloc(LEN);
                printf("Name: ");scanf("%s",Stu->name);
                none=getchar();
                printf("Sex and number: ");scanf("%c%d",&Stu->sex,&Stu->num);
                for(i=0;i<5;i++)
                {
                    printf("No.%d subject: ",i+1);scanf("%f",&Stu->score[i]);
                }

                head=Insert(head,Stu);
            }
            else if(*p==2)
            {
                printf("\nPlease input that student's number:\n");scanf("%d",num);none=getchar();
                head=Delete(head,num);
            }
            else if(*p==3)
            {
                head=Output(head);
            }
            else    {printf("Wrong request");}
            printf("\n\nPlease choose: ");
            p++;
        }
        else     break;
    }
    printf("\n\tBye-bye!\n");
    return 0;
}
