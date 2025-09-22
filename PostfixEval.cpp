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
/**********************************/
int evaluate(int x,int y,char symbol)
{
    switch(symbol)
    {
        case '+': return x+y;
        case '-': return x-y;
        case '*': return x*y;
        case '/': return x/y;
        case '^': return pow(x,y);
    }
    return 0;
}
/**********************************/
void postfixEvaluation(char postfix[])
{
    int i=0;
    initialize();
    while(postfix[i]!='\0')
    {
        char symbol=postfix[i];
        if(symbol>='0' && symbol<='9')
        {
            push(symbol-'0');
        }
        else
        {
            int y=pop();
            int x=pop();
            int value = evaluate(x,y,symbol);
            push(value);
        }
        i++;
    }
    cout<<"answer= "<< pop();
}
main()
{
    char postfix[100];
    cout<<"Enter a postfix expression: ";
    cin>>postfix;
    postfixEvaluation(postfix);
}