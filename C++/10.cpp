#include <iostream>
#include "Array.h"
using namespace std;

class Point {
public:
    Point(int xx = 0,int yy = 0) {
        x = xx;
        y = yy;
    };
    Point() {
        x = 0;
        y = 0;
    };
    Point(const Point& p) {
        x = p.x;
        y = p.y;
    };
    void setX(int x) {
        this->x = x;
    };
    int getX() {
        return x;
    };
    void setY(int y) {
        this->y = y;
    };
    int getY() {
        return y;
    };
    void setXY(int xx, int yy){
        x = xx;
        y = yy;
    }
    void print() {
        cout << "(" << x << "," << y << ")";
        return;
    };
    bool operator> (Point &p) {
        int pdis = p.x * p.x + p.y * p.y;
        int dis = x * x + y * y;
        return dis > pdis;
    }
    ~Point() {};
private:
    int x;
    int y;
};

class Date{
public:
    Date(int Year = 0, int Month = 0, int Day = 0) {
        year = Year;
        month = Month;
        day = Day;
    };
    Date(const Date& date) {
        year = date.year;
        month = date.month;
        day = date.day;
    }

    void print() {
        cout << year << '-' << month << '-' << day;
    };
    void setDate(int y, int m, int d) {
        year = y;
        month = m;
        day = d;
    }
    bool operator> (const Date &date){
        if(year != date.year)   return date.year > year;
        else if(month != date.month)    return date.month > month;
        else return date.day > day;
    } ;
    ~Date() {};
private:
    int year;
    int month;
    int day;
};

class Employee{
public:
    Employee(string first, string last, Date birth, Date hire): firstName(first), lastName(last), birthDate(birth), hireDate(hire){};
    Employee();
    Employee(const Employee& emp) {
        firstName = emp.firstName;
        lastName = emp.lastName;
        birthDate = emp.birthDate;
        hireDate = emp.hireDate;
    };
    void print() {
        cout << firstName << '-' << lastName << endl;
        birthDate.print();
    };
    Date &getBirthdate() {
        return birthDate;
    }
    ~Employee(){};
    bool operator> (Employee empl) {
        return birthDate > empl.birthDate;
    }
private:
    string firstName;
    string lastName;
    Date birthDate;
    Date hireDate;
};


template <class T>
T getMax(T a[], int num) {
    T maxT = a[0];
    int i;
    for(i = 0; i < num ; i++)
        if(a[i] > maxT) maxT = a[i];
    return maxT;
}

int main() {
    int choice = 0;
    while(1) {
        cin >> choice;
        if(choice == -1)    break;
        if(choice == 1) {
            Point points[3] = {Point(1, 5), Point(6, 3), Point(3, 7)};
            Point maxP = getMax(points, 3);
            maxP.print();
        }
        if(choice == 2) {
            Date date[3] = {Date(1995, 2, 4), Date(2000, 5, 3), Date(1983, 2, 3)};
            Date maxD = getMax(date, 3);
            maxD.print();
        }
        if(choice == 3) {
            Employee employees[3] = {Employee("Frank", "Dildo", Date(1678, 5, 1), Date(1700, 4, 2)),
                                    Employee("Richard", "Royce", Date(1874, 5, 3), Date(1800, 1, 5)),
                                    Employee("Dick", "Haggins", Date(1756, 4, 3), Date(1789, 4 , 2))};
            Employee maxEmpl = getMax(employees, 3);
            maxEmpl.print();
        }
    }


}
