#include<iostream>
#include<iomanip>
using namespace std;

class Date {
public:
    Date(int year = 1990, int month = 1, int day = 1);
    void setDate(int ,int ,int );
    void setYear(int );
    int getYear();
    void setMonth(int );
    int getMonth();
    void setDay(int );
    int getDay();
    void setSeparator(char separator);

    void printFullYear();
    void printStandardYear();

    int fullYearsTo(Date &date);
    int daysTo(Date &date);

    int getDayOfYear();
    int getLeftDaysLeftYear();

private:
    int year;
    int month;
    int day;
    char separator = '-';

    static const int DAYS_PER_MONTH[13];
    int checkDate();
    bool ifLeapYear();
};

class Employee{
public:
    Employee(string, string, Date&, Date&);
    Employee(const Employee&);
    void print();
    int getAge(Date &);
    int getYearsWorked(Date &);
    int getDaysWorked(Date &date);

private:
    string firstName;
    string lastName;
    Date birthDate;
    Date hireDate;
};

Date::Date(int Year, int Month, int Day) {
    year = Year;
    month = Month;
    day = Day;
}

Employee::Employee(string FirstName, string LastName, Date &Birth, Date &Hire) {
    firstName = FirstName;
    lastName = LastName;
    birthDate = Birth;
    hireDate = Hire;
}

const int Date::DAYS_PER_MONTH[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

void Date::setDate(int nuyear, int numonth, int nuday){
    year = nuyear;
    month = nuday;
    day = nuday;
}

void Date::setYear(int nuyear) {
    year = nuyear;
}

void Date::setMonth(int numonth) {
    month = numonth;
}

void Date::setDay(int nuday) {
    day = nuday;
}

int Date::getYear() {
    return year;
}

int Date::getMonth() {
    return month;
}

int Date::getDay() {
    return day;
}

void Date::setSeparator(char nuseparator) {
    separator = nuseparator;
}

void Date::printFullYear() {
    cout << year << separator << setw(2)
    << setfill('0') << setw(2) << month
    << separator
    << setfill('0') << setw(2) << day;
}

void Date::printStandardYear() {
    int standardYear = year % 100;
    cout << standardYear << separator << setw(2)
    << setfill('0') << setw(2) << month
    << separator
    << setfill('0') << setw(2) << day;
}

int Date::fullYearsTo(Date &toDate) {
    bool DaysFormer = toDate.month > month || toDate.month == month && toDate.day > day;
    if(DaysFormer)  return toDate.year - year;
    else return toDate.year - year - 1;
}

int Date::checkDate() {
    bool checkMonth = (month > 0 && month < 13);
    bool checkDay = (day > 0 && day < 32);
    return checkMonth && checkDay;
}

bool Date::ifLeapYear() {
    bool ifLeap = (year % 4 == 0 && year % 100 != 0 || year % 400 == 0);
    return ifLeap;
}

int Date::daysTo(Date &toDate) {
    const int daysofYear = 365;
    int sumDays = 0;
    bool ifYearLater = toDate.year > year;                   //Calculate the whole years first
    if (ifYearLater) {                                 //Original year later
        for (int i = year + 1; i < toDate.year; i++){
            if(ifLeapYear())  sumDays++;
            sumDays += daysofYear;
        }
        for(int i = month + 1; i <= 12; i++)
            sumDays += DAYS_PER_MONTH[i];
        sumDays += (DAYS_PER_MONTH[month] - day + 1);                    //1969.8.11     2010.4.15
        for(int i = 1; i < toDate.month - 1; i++)
            sumDays += DAYS_PER_MONTH[i];
        sumDays += toDate.day + 1;
        if(month <= 2 && ifLeapYear())  sumDays++;
        if(toDate.month > 2 && toDate.ifLeapYear()) sumDays++;
    }
    else {                                                 //Original year former
        for (int i = toDate.year + 1; i < year; i++){
            if(toDate.ifLeapYear())  sumDays--;
            sumDays -= daysofYear;
        }
        for(int i = 1; i < month; i++)
            sumDays -= DAYS_PER_MONTH[i];
        sumDays -= day;                         //1969.8.11    1949.10.1
        for(int i = toDate.month; i <= 12; i++)
            sumDays -= DAYS_PER_MONTH[i];
        sumDays += toDate.day + 1;
        if(month > 2 && ifLeapYear())  sumDays++;
        if(toDate.month < 2 && toDate.ifLeapYear()) sumDays++;
    }
    if (month == toDate.month)  {
        sumDays += toDate.day - day + 1;
        if(ifLeapYear() && month <= 2)  sumDays++;
        if(toDate.ifLeapYear() && toDate.month > 2)   sumDays++;
    }                                                       //Calculate the margin
    else if (month > toDate.month) {                        //Original month bigger
        for (int i = month + 1; i < toDate.day; i++)
            sumDays += DAYS_PER_MONTH[i];
        sumDays += DAYS_PER_MONTH[month] - day + 1;
        sumDays += toDate.day + 1;
        if(ifLeapYear() && month <= 2)  sumDays++;
        if(toDate.ifLeapYear() && toDate.month > 2)   sumDays++;
    }
    else {                                  //Original month smaller
        for (int i = toDate.month - 1; i > month; i--)
            sumDays -= DAYS_PER_MONTH[i];
        sumDays += DAYS_PER_MONTH[toDate.month] + 1; // 1900.4.7  1923.1.7
        if(ifLeapYear() && month > 2)    sumDays--;
        if(toDate.ifLeapYear() && toDate.month <= 2)  sumDays--;
    }
    return sumDays;
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

int Employee::getAge(Date &toDate) {
    return birthDate.fullYearsTo(toDate);
}

int Employee::getYearsWorked(Date &toDate) {
    return hireDate.fullYearsTo(toDate);
}

int Employee::getDaysWorked(Date &toDate) {
    return hireDate.daysTo(toDate);
}

int main() {
    Date birth(1969, 8, 11);
    Date hire(1998, 4, 1);
    Date today(2010, 4, 30);
    Employee manager("Bob", "Blue", birth, hire);
    cout << endl;
    manager.print();
    cout << endl;
    cout << manager.getAge(today) << endl;
    cout << manager.getDaysWorked(today) << endl;
    return 0;
}
