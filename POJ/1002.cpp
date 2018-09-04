#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

struct TEL{
    char seq[10];
    int occ;
};

bool cmp(TEL a,TEL b)
{
    for(int i=0;i<7;i++)
        if(a.seq[i]==b.seq[i])  continue;
        else return a.seq[i]<b.seq[i];
}

int main(){
    int n,place=0,len;
    bool ifexist=false;
    char news[20],s[20];
    TEL tel[100000];
    memset(news,0,sizeof(news));
    memset(s,0,sizeof(s));
    memset(tel,0,sizeof(tel));
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin>>s;
        len=strlen(s);
        for(int p=0,j=0;j<len;j++)
        {
            switch(s[j])
            {
            case '-':case 'Q':case 'Z':
                continue;
            case 'A':case 'B':case 'C':
                news[p++]='2';
                continue;
            case 'D':case 'E':case 'F':
                news[p++]='3';
                continue;
            case 'G':case 'H':case 'I':
                news[p++]='4';
                continue;
            case 'J':case 'K':case 'L':
                news[p++]='5';
                continue;
            case 'M':case 'N':case 'O':
                news[p++]='6';
                continue;
            case 'P':case 'R':case 'S':
                news[p++]='7';
                continue;
            case 'T':case 'U':case 'V':
                news[p++]='8';
                continue;
            case 'W':case 'X':case 'Y':
                news[p++]='9';
                continue;
            default:
                news[p++]=s[j];
                continue;
            }
        }
        for(int p=0;p<place;p++)
        {
            if(strcmp(tel[p].seq,news)==0)    {ifexist=true;tel[p].occ++;break;}
        }
        if(!ifexist)
        {
            strcpy(tel[place].seq,news);
            tel[place].occ++;
            place++;
        }
        ifexist=false;
    }
    sort(tel,tel+place,cmp);
    for(int i=0;i<place;i++)
    if(tel[i].occ>1)
    {
        for(int j=0;j<3;j++)    cout<<tel[i].seq[j];
        cout<<'-';
        for(int j=3;j<7;j++)    cout<<tel[i].seq[j];
        cout<<" "<<tel[i].occ<<endl;
    }
}
