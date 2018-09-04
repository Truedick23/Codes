#include "StackDemo.h"
#include "Cal.h"
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    char expression_1[] = {'8', '2', '-'};
    char expression_2[] = {'8', '2', '3', '/', '-'};
    char expression_3[] = {'8', '2', '-', '3', '/'};

    cout << "expression_1 = " << calculate(expression_1, 3) << endl;
    cout << "expression_2 = " << calculate(expression_2, 5) << endl;
    cout << "expression_3 = " << calculate(expression_3, 5) << endl;
    return 0;
}
