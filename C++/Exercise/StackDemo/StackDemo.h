#ifndef STACKDEMO1_H_INCLUDED
#define STACKDEMO1_H_INCLUDED

#include <iostream>
#include "Array.h"
using namespace std;

template <class T>
class Stack {
public:
    virtual void push(T ) = 0;
    virtual void pop()  = 0;
    virtual T& top() = 0;
    virtual bool empty() = 0;
};

template <class T>
class MyStack: public Stack<T> {
public:
    MyStack(int n) {
        array.resize(n);
        place = 1;
    };
    void push(T element)    {
        array[++place]= element;;
    };
    void pop()  {
        if(place > 0)
            place--;
        else cout << "Popping is N/A" << endl;
    };
    T& top() {
        return array[place];
    };
    bool empty() {
        if (place == 0)
            return true;
        else return false;
    };
    T& back() {
        return array[1];
    };
    ~MyStack() {};
private:
    Array<T> array;
    int place;
};

#endif // STACKDEMO1_H_INCLUDED
