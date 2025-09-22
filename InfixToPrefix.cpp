#include<iostream>
#include<math.h>
#include<vector>
#include<string.h>
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
char pop()
{
    char x;
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
/*********************************/
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
void prefixEvaluation(char prefix[])
{
    int i=0;
    initialize();
    while(prefix[i]!='\0')
    {
        i++;
    }
    i--;
    while(i>=0)
    {
        char symbol=prefix[i];
        if(symbol>='0' && symbol<='9')
        {
            push(symbol-'0');
        }
        else
        {
            int x=pop();
            int y=pop();
            int value = evaluate(x,y,symbol);
            push(value);
        }
        i--;
    }
    cout<<"answer= "<< pop();
}
/**********************************/
bool prcd(char op1, char op2)
{
    if(op1=='^'||op1=='*'||op1=='/'||op1=='%')
    {
        if(op2=='^')
            return false;
        else
            return true;
    }
    else if(op1=='+'||op1=='-')
    {
        if(op2=='+'||op2=='-')
            return true;
        else
            return false;
    }
}
/**********************************/
int main()
{
    char Infix[30];
    vector<char> prefix;
    cout<<"Enter an infix expression: ";
    cin>>Infix;
    initialize();
    int i=0;
    while(Infix[i]!='\0')
        i++;
    
    i=i-1;
    while(i>=0)
    {
        char symb=Infix[i];
        if(symb>='a'&&symb<='z' || symb>='A'&&symb<='Z' || symb>='0'&&symb<='9')
        {
            prefix.push_back(symb);
        }
        else
        {
            while(!isEmpty() && !prcd(symb,stacktop()))
            {
                char x= pop();
                prefix.push_back(x);
            }
            push(symb);
        }
        i--;
    }
    while(!isEmpty())
    {
        char x= pop();
        prefix.push_back(x);
    }
    for(int i=prefix.size()-1;i>=0;i--)
        cout<<prefix[i];
    return 0;
}