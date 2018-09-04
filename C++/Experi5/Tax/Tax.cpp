#include<iostream>
#include<iomanip>
#include<vector>
using namespace std;
#define MAXN 9999999

struct Rule {
    double percent;
    int range;
}rules[1000];

void inputRules(struct Rule rules[], int n) {
    rules[0].range = 0;
    rules[0].percent = 0;
    for(int i = 1; i <= n; i++) {
        cout << "Please input the No. " << i << " rule: ";
        cin >> rules[i].range >> rules[i].percent;
    }
    rules[n + 1].range = MAXN;
}

void showRules(struct Rule rules[], int n) {
    cout << "The rules for tax: " << endl;
    cout << "Tax range       Tax rate" << endl;
    for(int i = 1; i <= n; i++) {
        cout << "  " << setw(4) << rules[i].range << "       " << setw(4) << rules[i].percent << endl;
    }
    return;
}

double computeTax(struct Rule rules[], int n, int income) {
    double totaltax = 0;
    double percentage = 0;
    for(int i = 1; i < n; i++) {
            if(income < rules[i].range) break;
            percentage = rules[i].percent / 100.0;
            if(income > rules[i + 1].range)
                totaltax += (rules[i + 1].range - rules[i].range) * percentage;
            else {
                totaltax += (income - rules[i].range) * percentage;
                break;
            }
    }
    if(income > rules[n].range)  {
        percentage = rules[n].percent / 100.0;
        totaltax += (income - rules[n].range) * percentage;
     }
    return totaltax;
}

int main() {
    int numberOfRules = 0;
    int income = 0;
    double tax = 0;
    cout << "Please input the number of rules: ";
    cin >> numberOfRules;
    inputRules(rules, numberOfRules);
    showRules(rules, numberOfRules);
    while(true) {
        cout << "Please input your income: ";
        cin >> income;
        if(income == -1) {
            cout << "Bye-bye" << endl;
            break;
        }
        tax = computeTax(rules, numberOfRules, income);
        cout << "Your income: " << income << ", tax you should pay: " << tax << endl;
    }
    return 0;
}
