#include <iostream>
#include "Operator.h"
using namespace std;

int main(){
    Date currentDate(2017, 5, 17);
    Employee employee[5] = {Employee("Gary", "Tom", Date(1978, 2, 5), Date(2000, 3, 4)),
        Employee("Ramon", "Buck", Date(1968, 5, 6), Date(1992, 3, 5)),
        Employee("Paul", "West", Date(1976, 4, 3), Date(1998, 2, 3)),
        Employee("Noah", "Ethan", Date(1996, 5, 4), Date(2013, 3, 5)),
        Employee("Tyson", "Oedipus", Date(1992, 11, 23), Date(2004, 4, 2))
    };
    Employee mostFaith = mostFaith.getMostFaith(employee, 5);
    mostFaith.print();
    int workDays = mostFaith.getHireDate() - currentDate;
    cout << "He has been worked for " << workDays << " days" << endl;
    return 0;

}
