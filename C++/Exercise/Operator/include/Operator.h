#ifndef OPERATOR_H
#define OPERATOR_H


#include <iostream>
#include <iomanip>
using namespace std;

class Date {
public:
    Date(int year, int month, int day);
    Date(const Date &date);
    Date() {};
    ~Date(){};
    int operator- (const Date &date2) const;
    bool operator> (const Date &date2);
    bool operator< (const Date &date2);
    void printFullYear();
    void printStandardYear();
private:
    int year;
    int month;
    int day;
};

class Employee {
public:
    Employee(string, string, Date, Date);
    Employee(const Employee &);
    Employee() {};
    void setInformation(string, string, Date, Date);
    void print();
    ~Employee() {
    };
    Employee& getMostFaith(Employee employees[], int n);
    Date getHireDate() {
        return hireDate;
    }
private:
    string firstName;
    string lastName;
    Date birthDate;
    Date hireDate;
};

#endif // OPERATOR_H
