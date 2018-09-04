#include<iostream>
#include<iomanip>
#include<cstring>
using namespace std;

int main() {
    int sec, format[4];
    while (cin >> sec) {
        memset (format, 0, sizeof(format));
        for(int i = 3; i >= 2; i--) {
            format[i] = sec % 60;
            sec /= 60;
        }
        format[1] = sec % 24;
        format[0] = sec / 24;
        cout << format[0] << "day(s),";
        cout << setfill('0') << setw(2) << format[1] << ":";
        cout << setfill('0') << setw(2) << format[2] << ":";
        cout << setfill('0') << setw(2) << format[3] << endl;
    }
    return 0;
}
