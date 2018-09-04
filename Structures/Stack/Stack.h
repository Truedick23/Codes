#ifndef STACK_H
#define STACK_H

template <class T>
class Stack {
private:
    T *m_Data;
    int m_buffSize;
    int m_nCount;
    const int m_onceAlloc;
public:
    Stack(int buffSize = 0);
    ~Stack();
    bool DestroyStack;
    bool Clear();
    bool isEmpty();
    int GetLength();
    const T GetTop();
    bool Push(const T &elem);
    bool Pop();
};


#endif // STACK_H
