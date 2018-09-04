#ifndef EMPLOYEE_H_INCLUDED
#define EMPLOYEE_H_INCLUDED

#include"Date.h"

class Employee {
public:
    Employee(string, string, Date&, Date&);
    Employee(const Employee &);
    Employee() {};
    void setInformation(string, string, Date&, Date&);
    void print();
    static const Employee& getMosFaith(const Employee employees[], int n);
    ~Employee();
private:
    string firstName;
    string lastName;
    Date birthDate;
    Date hireDate;
};

#endif // EMPLOYEE_H_INCLUDED
