#include<iostream>
#include<cstring>
using namespace std;

struct Haab{
    int year;
    int month;
    int days;
};

struct Tzolkin{
    int year;
    int month;
    int days;
};

char hmonth[20][10]={"pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol",
    "chen", "yax", "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu"};

char tdays[20][10]={"imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat",
    "muluk", "ok", "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau"};

void haabmonth(Haab &a,char b[])
{
    int i;
    for(i=0;i<20;i++)
        if(strcmp(hmonth[i],b)==0)  break;
    a.month=i;
}

void tzolkinday(Tzolkin &a, char b[])
{
    int i;
    for(i=0;i<20;i++)
        if(strcmp(tdays[i],b)==0)   break;
    a.days=i;
}

void tzolkinmanip(Tzolkin &a, int total)
{
    a.year=total/260;
    total-=a.year*260;
    a.month=total%13+1;
    a.days=total%20;
}

int main(){
    int n;
    char point=0;
    char hm[10],td[10];
    int total=0;
    Haab haab[10000];
    Tzolkin tzolkin[10000];
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>haab[i].days>>point>>hm>>haab[i].year;
        haabmonth(haab[i],hm);
        total=haab[i].year*365+haab[i].month*20+haab[i].days;
        tzolkinmanip(tzolkin[i],total);
        point=0;
        total=0;
    }
    cout<<n<<endl;
    for(int i=0;i<n;i++)
        cout<<tzolkin[i].month<<" "<<tdays[tzolkin[i].days]<<" "<<tzolkin[i].year<<endl;
    return 0;
}
