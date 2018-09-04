#include <cstdio>
#include <cmalloc>
#include <cstdlib>
#include <queue>
#include <stack>
#include <iostream>
using namespace std;
typedef struct BiNode{
    char data;
    BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

void CreatBiTree(BiTree &T) {
    char ch;
    cin >> ch;
    if(ch == '')    {
        T = NULL;
        return;
    }
    else {
        T = (BiTree)malloc(sizeof(BiTNode))
        if(!T)
            exit(1);
        T->data = ch;
        CreateBiTree(T -> lchild);
        CreateBiTree(T -> rchild);
    }
}

void InOrderTraverse(BiTree T) {
    stack<BiTree>  Stack;
    if(!T) {
        cout << "Empty!" << endl;
        return;
    }
    while(T || !Stack.empty()) {
        while(T) {
            Stack.push(T);
            T = T -> lchild;
        }
        T = Stack.top();
        Stack.pop();
        cout << T -> data;
        T = T -> rchild;
    }
}

void PreOrderTraverse(BiTree T) {
    Stack<BiTree> Stack;
    if(!T)  {
        cout << "Empty!" << endl;
        return;
    }
    while(T || !Stack.empty()){
        while(T) {
            Stack.push(T);
            cout << T -> data;
            T = T -> lchild;
        }
        T = Stack.top();
        Stack.pop();
        T = T -> rchild;
    }
}

void PostOrderTraverse(BiTree T) {
    int flag[20];
    stack<BiTree>  Stack;
    if(!T)  {
        cout << "Empty!" << endl;
        return;
    }
    while(T) {
        Stack.push(T);
        flag[Stack.size()] = 0;;
    }
}
