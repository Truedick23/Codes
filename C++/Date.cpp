#include<iostream>
#include<iomanip>
using namespace std;

class Date{
public:
    Date(int year = 1990, int month = 1, int day = 1, char separator = '-');
    void setDate(int year, int month, int day);
    void setYear(int year);
    int getYear();
    void setMonth(int month);
    int getMonth();
    void setDay(int day);
    int getDay();
    void setSeparator(char separator);
    void printFullYear();
    void printStandardYear();
    int fullYearsTo(int year, int month, int day);
    int daysTo(int year, int month, int day);
private:
    int year;
    int month;
    int day;
    char separator;
};

int main() {
    Date birthDate(1969, 8 ,11);
    birthDate.printFullYear();
    birthDate.printStandardYear();
    birthDate.setSeparator('*');

    cout << birthDate.fullYearsTo(2010, 4, 15) << endl;
    cout << birthDate.daysTo(2010, 4, 15) << endl;
    cout << birthDate.daysTo(1949, 10, 1) << endl;
    return 0;
}

Date::Date(int Year, int Month, int Day, char Separator) {
    year = Year;
    month = Month;
    day = Day;
    separator = Separator;
}

bool ifLeepYear(int year) {
    if((year % 400 == 0)||(year % 4 == 0 && year % 25 != 0)) return true;
    else return false;
}

void Date::setDate(int Year, int Month, int Day){
    year = Year;
    month = Month;
    day = Day;
}

void Date::setYear(int Year) {
    year = Year;
}

int Date::getYear() {
    return year;
}

void Date::setMonth(int Month) {
    month = Month;
}

int Date::getMonth() {
    return month;
}

void Date::setDay(int Day) {
    day = Day;
}

int Date::getDay()  {
    return day;
}

void Date::setSeparator(char Separator) {
    separator = Separator;
}

void Date::printFullYear() {
    cout << year << separator;
    cout << setfill('0') << setw(2) << month << separator;
    cout << setfill('0') << setw(2) << day << endl;
}

void Date::printStandardYear() {
    int standardYear = year % 100;
    cout << standardYear << separator;
    cout << setfill('0') << setw(2) << month << separator;
    cout << setfill('0') << setw(2) << day << endl;
}

int Date::fullYearsTo(int toYear, int toMonth, int toDay) {
    int marg = -1;
    if(toMonth > month || toMonth == month && toDay < day)
        marg = 0;
    return toYear - year + marg;
}

int Date::daysTo(int toYear, int toMonth, int toDay) {
    int daysofMonths[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int daysofYear = 365;
    int sumDays = 0;
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



