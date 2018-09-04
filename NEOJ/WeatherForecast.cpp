#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<cstdio>
#include<cstring>
using namespace std;

void inputTemp(int temp[], int n);

void displayTemps(int temp[], int n);

void displayPeaks(int temp[], int n);

void displayFlat(int temp[], int n);

void displayMajor(int temp[], int n);

int main() {
    int temp[30], n, d;
    cin >> d;
    inputTemp(temp, d);
    displayTemps(temp, d);
    displayPeaks(temp, d);
    displayFlat(temp, d);
    displayMajor(temp, d);
    return 0;
}

void inputTemp(int temp[], int n) {
    for(int i = 1; i <= n; i++) {
        cin >> temp[i];
    }
    return;
}

void displayTemps(int temp[], int n) {
    int k;
    for(int i=1; i <= n; i++) {
        cout << setw(5) << i ;
        if(temp[i] < 0) k = 1;
        else k = 0;
        if (k) {
            for(int l = 1 ; l <= 10 + temp[i]; l++)
                cout << " ";
            for(int j = -1; j >= temp[i]; j--)
                cout << "*";
            cout << "|";
        }
        else {
            for(int j = 1; j <= 10; j++)
                cout << " ";
            cout << "|";
            for(int j = 1; j <= temp[i]; j++)
                cout << "*";
        }
        cout << endl;
    }
    return;
}

void displayPeaks(int temp[], int n) {
    int maxTemps[30];
    memset(maxTemps, 0, sizeof(maxTemps));
    for(int i = 2; i < n; i++)
        if(temp[i] > temp[i-1] && temp[i] > temp[i+1])   maxTemps[i] = temp[i];
    cout << "The peaks of temperature are: " << endl;
    for(int i = 2; i < n; i++)
        if(maxTemps[i])  cout << "Max at day " << i << " is " << maxTemps[i] << endl;
}

void displayFlat(int temp[], int n) {
    int maxLength = 0, k = 0, length = 1;
    for(int i = 2; i <= n; i++)
    if (temp[i] == temp[i-1]) {
        k = 1;
        length++;
        if (length > maxLength) maxLength = length;
    }
    else {
        k = 0;
        length = 1;
    }
    cout << "The length of the longest flat is: " << maxLength << endl;
}

void displayMajor(int temp[], int n) {
    int times[100], maxTimes = 0, maxTemp = 50, place;
    memset(times, 0, sizeof(times));
    for(int i = 1; i <= n; i++) {
        place = 50 + temp[i];
        times[place]++;
    }

    for(int i = 0; i <= 99; i++)
        if (times[i] > maxTimes) {
            maxTimes = times[i];
            maxTemp = i - 50;
        }
    cout << "The most frequently occurred temperature is " << maxTemp << " with the times of " << maxTimes << endl;
}
