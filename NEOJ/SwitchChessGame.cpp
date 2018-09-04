#include<iostream>
using namespace std;
#include<cstring>
#include<cstdio>
#include<algorithm>

void getFormat(char Format[], int type);

bool ifFinal(char Format[]);

void printNext(char Format[], int n);

void Move(char Format[], int Eplace, int replac);

int placeB[10], placeW[10], times = 0;

int main(){
    int n, i, type, Eplace;
    char Format[20];
    cin >> n;
    for(i = 0; i < n; i++) {
        cin >> type;
        cin >> Format;
        cout << "Result No. " << ++times << ":" << endl;
        if(ifFinal(Format)) {cout << "This is the final format." << endl; return 0;}
        for(int j = 0; j <= strlen(Format); j++)
            if (Format[j] == 'E')   Eplace = j + 1;
        printNext(Format, Eplace);
    }
    return 0;
}

bool ifFinal(char Format[]) {
    memset(placeB, 0, sizeof(placeB));
    memset(placeW, 0, sizeof(placeW));
    for(int i = 0; i <= strlen(Format); i++)
    {
        if (Format[i] == 'B') placeB[i] = 1;
        if (Format[i] == 'W') placeW[i] = 1;
    }
    for(int i = 0; i < 10; i++)
        if(placeB[i] == 1) {
            for(int j = i; j < 10; j++)
                if(placeW[j] == 1)  return false;
    return true;
    }
}

void printNext(char Format[], int Eplace) {
    int length = strlen(Format);
    int LMargin, RMargin;
    int places[7] = {-3, -2, -1, 0, 1, 2, 3};
    int const num = 6;
    LMargin = Eplace - 1;
    RMargin = length - Eplace;
    for(int i = 0; i <= num; i++)
        if (Format[Eplace - 1 + places[i]] == '\0') places[i] = 10;
    for(int i = 0; i <= num; i++)
        if (places[i] == 10)    break;
        else for(int j = i + 1; j <= num; j++)
                if(Format[Eplace - 1 + places[i]] < Format[Eplace -1 + places[j]])   swap(places[i], places[j]);
        for(int i = 0; i <= num; i++)
            if (places[i])
                Move(Format, Eplace, places[i]);
}

void Move(char Format[],int EPlace, int replac) {
    int i, k = 1;
    char temp, FormatDash[20];
    EPlace--;
    strcpy(FormatDash, Format);
    temp = FormatDash[EPlace];
    FormatDash[EPlace] = FormatDash[EPlace + replac];
    FormatDash[EPlace + replac] = temp;
    for(i = 0; i < strlen(FormatDash); i++)
        if(FormatDash[i]!='B'&&FormatDash[i]!='W'&&FormatDash[i]!='E')  k = 0;
    if(k) cout << FormatDash << endl;
}
