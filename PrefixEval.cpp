#include<iostream>
#include<math.h>
#include<vector>
#include<stdlib.h>
#define stacksize 100
using namespace std;
struct stk
{
    int item[100];
    int top;
};
struct stk s;
/**********************************/
void initialize()
{
    s.top=-1;
}
/**********************************/
bool isEmpty()
{
    if(s.top==-1)
        return true;
    else
        return false;
}
/**********************************/
void push(int x)
{
    if(s.top==99)
    {
        cout<<"Stack Overflow"<<endl;
        exit(1);
    }
    else
    {
        s.top++;
        s.item[s.top]=x;
    }
}
/**********************************/
int pop()
{
    int x;
    if(isEmpty())
    {
        cout<<"Stack Underflow"<<endl;
        exit(1);
    }
    else
    {
        x=s.item[s.top];
        s.top--;
        return x;
    }
}
/**********************************/
int stacktop()
{
    return s.item[s.top];
}