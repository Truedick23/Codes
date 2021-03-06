#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

class Date {
public:
    Date(int year, int month, int day);
    Date(const Date &date);
    Date() {};
    ~Date() {};
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

Date::Date(int year, int month, int day)    {
    this -> year = year;
    this -> month = month;
    this -> day = day;
}

Date::Date(const Date &date) {
    year = date.year;
    month = date.month;
    day = date.day;
}

bool ifLeepYear(int year) {
    if((year % 400 == 0)||(year % 4 == 0 && year % 25 != 0)) return true;
    else return false;
}

void Date::printFullYear() {
    cout << year << '-';
    cout << setfill('0') << setw(2) << month << '-';
    cout << setfill('0') << setw(2) << day << endl;
}

void Date::printStandardYear() {
    int standardYear = year % 100;
    cout << standardYear << '-';
    cout << setfill('0') << setw(2) << month << '-';
    cout << setfill('0') << setw(2) << day << endl;
}

int Date::operator- (const Date &date2) const {
    int daysofMonths[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int daysofYear = 365;
    int sumDays = 0;
    const int toYear = date2.year;
    const int toMonth = date2.month;
    const int toDay = date2.day;
    bool ifYearLater = toYear > year;                   //Calculate the whole years first
    if (ifYearLater) {                                 //Original year later
        for (int i = year + 1; i < toYear; i++){
            if(ifLeepYear(i))  daysofYear++;
            sumDays += daysofYear;
            daysofYear = 365;
        }
        for(int i = month + 1; i <= 12; i++)
            sumDays += daysofMonths[i];
        sumDays += (daysofMonths[month] - day - 1);                    //1969.8.11     2010.4.15
        for(int i = 1; i < toMonth - 1; i++)
            sumDays += daysofMonths[i];
        sumDays += toDay - 1;
        if(month <= 2 && ifLeepYear(year))  sumDays++;
        if(toMonth > 2 && ifLeepYear(toYear)) sumDays++;
    }
    else {                                                 //Original year former
        for (int i = toYear + 1; i < year; i++){
            if(ifLeepYear(i))  daysofYear++;
            sumDays -= daysofYear;
            daysofYear = 365;
        }
        for(int i = 1; i < month; i++)
            sumDays -= daysofMonths[i];
        sumDays -= day;                         //1969.8.11    1949.10.1
        for(int i = toMonth; i <= 12; i++)
            sumDays -= daysofMonths[i];
        sumDays += toDay - 1;
        if(month > 2 && ifLeepYear(year))  sumDays++;
        if(toMonth < 2 && ifLeepYear(toYear)) sumDays++;
    }
                                            //Calculate the margin
    if (month >= toMonth) {                 //Original month bigger
        for (int i = month + 1; i < toMonth; i++)
            sumDays += daysofMonths[i];
        sumDays += daysofMonths[month] - day - 1;
        sumDays += toDay - 1;
        if(ifLeepYear(year) && month <= 2)  sumDays++;
        if(ifLeepYear(toYear) && toMonth > 2)   sumDays++;
    }
    else {                                  //Original month smaller
        for (int i = toMonth - 1; i > month; i--)
            sumDays -= daysofMonths[i];
        sumDays += daysofMonths[toMonth]; // 1900.4.7  1923.1.7
        if(ifLeepYear(year) && month > 2)    sumDays--;
        if(ifLeepYear(toYear) && toMonth <= 2)  sumDays--;
    }
    return sumDays;
}

bool Date::operator> (const Date &date2) {
    if(year != date2.year)  return year > date2.year;
    if(month != date2.month)    return month > date2.month;
    if(day != date2.day)    return day > date2.day;
}

bool Date::operator< (const Date &date2) {
    if(year != date2.year)  return year < date2.year;
    if(month != date2.month)    return month < date2.month;
    if(day != date2.day)    return day < date2.day;
}

Employee::Employee(const string firstName, const string lastName, Date birthDate, Date hireDate) {
    this -> firstName = firstName;
    this -> lastName = lastName;
    this -> birthDate = birthDate;
    this -> hireDate = hireDate;
}

void Employee::print() {
    cout << "Employee Information:" << endl;
    cout << "First Name: " << firstName << endl;
    cout << "Last Name: " << lastName << endl;
    cout << "Birth Date: ";
    birthDate.printFullYear();
    cout << endl << "Hire Date: ";
    hireDate.printStandardYear();
    cout << endl;
}

void Employee::setInformation(const string firstName, const string lastName, Date birthDate, Date hireDate) {
    this -> firstName = firstName;
    this -> lastName = lastName;
    this -> birthDate = birthDate;
    this -> hireDate = hireDate;
}

Employee::Employee(const Employee &employee) {
    firstName = employee.firstName;
    lastName = employee.lastName;
    birthDate = employee.birthDate;
    hireDate = employee.hireDate;
}

Employee& Employee::getMostFaith(Employee employees[], int n) {
    int place = 0;
    for(int i = 0; i < n; i++)
            if(employees[i].getHireDate() < employees[place].getHireDate())
                place = i;
    return employees[place];
}

int main()
{
    int num;
    Date currentDate(2017, 5, 10);

    Employee employee[5] = {Employee("Gary", "Tom", Date(1978, 2, 5), Date(2000, 3, 4)),
        Employee("Ramon", "Buck", Date(1968, 5, 6), Date(1992, 3, 5)),
        Employee("Paul", "West", Date(1976, 4, 3), Date(1998, 2, 3)),
        Employee("Noah", "Ethan", Date(1996, 5, 4), Date(2013, 3, 5)),
        Employee("Tyson", "Oedipus", Date(1992, 11, 23), Date(2004, 4, 2))
    };
    Employee mostFaith = mostFaith.getMostFaith(employee, 5);
    mostFaith.print();
    int workDays = mostFaith.getHireDate() - currentDate;
    cout << "He has been worked for " << workDays << "days" << endl;
    return 0;
}
