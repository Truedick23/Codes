#ifndef CAL_H_INCLUDED
#define CAL_H_INCLUDED
#include "StackDemo.h"

double calculate(char expression[], int num) {
    MyStack <double> mystacks(100);
    Stack <double> &stacks = mystacks;
    for(int i = 0; i < num; i++) {
        if(expression[i] >= '0' && expression[i] <= '9')
            stacks.push(expression[i] - '0');
            else if(expression[i] == '+')   {
                double num1 = stacks.top();
                stacks.pop();
                double num2 = stacks.top();
                stacks.pop();
                stacks.push(num2 + num1);
            }
            else if(expression[i] == '-'){
                double num1 = stacks.top();
                stacks.pop();
                double num2 = stacks.top();
                stacks.pop();
                stacks.push(num2 - num1);
            }
            else if(expression[i] == '*')   {
                double num1 = stacks.top();
                stacks.pop();
                double num2 = stacks.top();
                stacks.pop();
                stacks.push(num2 * num1);
            }
            else if(expression[i] == '/')   {
                double num1 = stacks.top();
                stacks.pop();
                double num2 = stacks.top();
                stacks.pop();
                stacks.push(num2 / num1);
            }
        }
        double top = mystacks.top();
        return top;
}



#endif // CAL_H_INCLUDED
