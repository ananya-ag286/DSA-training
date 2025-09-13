#include<iostream>
#include<math.h>
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
char stacktop()
{
    return s.item[s.top];
}
/**********************************/
void decimalToBinary(int n)
{
    initialize();
    while(n!=0)
    {
        
        int r=n%2;
        push(r);
        n=n/2;
    }
    while(!isEmpty())
    {
        int x=pop();
        cout<<x;
    }
}
/**********************************/
void decimalToOctal(int n)
{
    initialize();
    while(n!=0)
    {
        
        int r=n%8;
        push(r);
        n=n/8;
    }
    while(!isEmpty())
    {
        int x=pop();
        cout<<x;
    }
}
/*********************************/
void decimalToHexadecimal(int n)
{
    initialize();
    char DAT[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    while(n!=0)
    {
        
        int r=n%16;
        push(r);
        n=n/16;
    }
    while(!isEmpty())
    {
        int x=pop();
        cout<<DAT[x];
    }
}
/*********************************/
void decimalToAnyBase(int n,int b)
{
    initialize();
    char DAT[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    while(n!=0)
    {
        
        int r=n%b;
        push(r);
        n=n/b;
    }
    while(!isEmpty())
    {
        int x=pop();
        cout<<DAT[x];
    }
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
    // /*initialize();
    // push(10);
    // push(20);
    // push(30);
    // cout<<pop()<<endl;
    // cout<<stacktop()<<endl;*/
    // int n;
    // cout<<"Enter a decimal number: ";
    // cin>>n;
    // decimalToBinary(n);
    // decimalToOctal(n);
    // decimalToHexadecimal(n);
    // decimalToAnyBase(n,2);
    // decimalToAnyBase(n,8);
    // decimalToAnyBase(n,16);
    // char postfix[100];
    // cout<<"Enter a postfix expression: ";
    // cin>>postfix;
    // postfixEvaluation(postfix);
    // char prefix[100];
    // cout<<"Enter a prefix expression: ";
    // cin>>prefix;
    // prefixEvaluation(prefix);
    char Infix[30];
    vector<char>postfix;
    cin>>Infix;
    int i=0;
    initialize();
    while(postfix[i]!='/0')
    {
        char symb=postfix[i];
        if(symb<='a'&&symb>='z')
        {
            postfix.push_back(symb);
        }
        else
        {
            while(!isEmpty&&prcd(stacktop(),symb))
            {
                char x=pop();
                postfix.push_back(x);
            }
            push(symb);
        }
        i++;
    }
    while(!isEmpty())
    {
        char x=pop();
        postfix.push_back(x);
    }
    for(int i=0;i<postfix.size();i++)
        cout<<postfix[i];
    return 0;
}