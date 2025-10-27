#include <iostream>
#include <stdlib.h>
#define maxqueue 10
using namespace std;
struct Queue
{
    int item[maxqueue];
    int front;
    int rear;
};
Queue q;
/**********************************/
void initialise()
{
    q.front = 0;
    q.rear = -1;
}
/**********************************/
bool isempty()
{
    if(q.rear-q.front+ 1 == 0)
        return true;
    else
        return false;
}
/**********************************/
void enqueue(char x)
{
    if(q.rear == maxqueue - 1)
    {
        cout<<"Queue Overflow"<<endl;
        exit(1);
    }
    else
    {
        q.rear++;
        q.item[q.rear]=x;
    }
}
/**********************************/
char dequeue()
{
    if(isempty())
    {
        cout<<"Queue Underflow"<<endl;
        exit(1);
    }
    else
    {
        char x=q.item[q.front];
        q.front++;
        return x;
    }
}
int main()
{
    initialise();
    enqueue('A');
    enqueue('B');
    enqueue('C');
    enqueue('D');
    enqueue('E');
    enqueue('F');
    enqueue('g');
    enqueue('h');
    enqueue('i');
    // enqueue('j');
    // enqueue('k');
    // char x=dequeue();
    // cout<<"Dequeued element: "<<x<<endl;
    // x=dequeue();
    // cout<<"Dequeued element: "<<x<<endl;
    x=dequeue();
    cout<<"Dequeued element: "<<x<<endl;
    x=dequeue();
    cout<<"Dequeued element: "<<x<<endl;
    x=dequeue();
    cout<<"Dequeued element: "<<x<<endl;
    x=dequeue();
    cout<<"Dequeued element: "<<x<<endl;
    x=dequeue();
    cout<<"Dequeued element: "<<x<<endl;
    return 0;
}