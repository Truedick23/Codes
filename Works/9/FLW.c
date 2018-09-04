#include<stdio.h>
struct flower
{
    int num;
    double sum;
    double aver;
}a[100],aa[100];

struct vote
{
    int choice;
    double point;
}b[1000];

void aver()
{
    struct flower *p;
    struct vote *v;
    p=a;v=b;
    int c;
    for(;v->point!=0;v++)
    {
        c=v->choice;
        (p+c)->num++;
        (p+c)->sum+=v->point;
    }
    for(;p-a<100;p++)
    {
        if(p->num!=0)
        p->aver=p->sum/p->num;
    }
    return;
}

void write()
{
    FILE *f1;
    f1=fopen("flower.dat","wb");
    struct flower *p;
    for(p=a;p-a<100;p++)
    {
        fwrite(&p->num,sizeof(int),1,f1);
        fwrite(&p->sum,sizeof(double),1,f1);
        fwrite(&p->aver,sizeof(double),1,f1);
    }
    fclose(f1);
    return;
}

void champ()
{
    struct flower *p;
    int ch=0,k,i;
    double max;
    FILE *f2;
    f2=fopen("flower.dat","rb");
    for(p=aa;(p-aa)<100;p++)
    {
        fread(&p->num,sizeof(int),1,f2);
        fread(&p->sum,sizeof(double),1,f2);
        fread(&p->aver,sizeof(double),1,f2);
    }
    printf("The total result: \n\n");
    for(k=0,i=0,max=0,p=aa;(p-aa)<100;p++,i++)
    {
        if(p->num!=0)
            {
                k=1;
                printf("About No.%d flower:\nVote number: %d\nTotal point: %.4f\nAverage score: %.4f\n\n",i,p->num,p->sum,p->aver);
            }
        if(k)
        {
            if(p->aver>max)    {max=p->aver;ch=i;}
        }
        k=0;
    }
    printf("\n\nThe champion is No.%d flower, with the average score of %.3lf! \n",ch,max);
    fclose(f2);
}
void vote()
{
    int n=0,i;
    struct vote *p;
    p=b;
    for(i=0;i<1000;i++)
    {
        b[i].point=0;
    }
    printf("Please vote!\n\nYour No.%d vote: \nFlower number:",++n);
    while(scanf("%d",&p->choice)!=EOF)
    {
        printf("Her point:");
        scanf("%lf",&p->point);
        p++;
        printf("\nYour No.%d vote:\nFlower number:",++n);
    }
    printf("Voting is over! Thanks for voting!\n\n");
    for(i=0;i<20;i++)
    {
        printf(".\n");
    }
    return;
}

void memset()
{
    struct flower *p;
    for(p=a;p-a<100;p++)
    {
        p->num=0;p->sum=0;p->aver=0;
    }
    for(p=aa;p-aa<100;p++)
    {
        p->num=0;p->sum=0;p->aver=0;
    }
}
int main()
{
    memset();
    vote();
    aver();
    write();
    champ();
    return 0;
}
