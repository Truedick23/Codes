#include "Date.h"

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

