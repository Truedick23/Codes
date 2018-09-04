#include <iostream>
#include <algorithm>
using namespace std;

class Date {
public:
    Date(int year, int month, int day);
    Date(const Date &date);
    Date() {};
    ~Date();
    int operator- (const Date &date2) const;
    bool operator> (const Date &date2);
    bool operator< (const Date &date2);
private:
    int year;
    int month;
    int day;
}

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
    return date2 < *this;
}

Employee::Employee(string firstName, string lastName, Date birthDate, Date hireDate) {
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

void Employee::getInformation(string firstName, string lastName, Date birthDate, Date hireDate) {
    this -> firstName = firstName;
    this -> lastName = lastName;
    this -> birthDate = birthDate;
    this -> hireDate = hireDate;
}

static const Employee& Employee::getMostFaith(const Employee employees[], int n) {
    sort(employees, n);
    return employees[0];
}

int main()
{
    int num;
    cout << "Number of employees:";
    cin >> num;
    Date currentDate(2017, 5, 10);
    employee = new Employee*[num];
    employee[0].setInformation("Gary", "Tom", (1978, 2, 5), (2000, 3, 4));
    employee[1].setInformation("Ramon", "Buck", (1968, 5, 6), (1992, 3, 5));
    employee[2].setInformation("Paul", "West", (1976, 4, 3), (1998, 2, 3));
    employee[3].setInformation("Noah", "Ethan" (1996, 5, 4), (2013, 3, 5));
    employee[4].setInformation("Tyson", "Oedipus", (1992, 11, 23), (2004, 4, 2));
    return 0;
}
