#include <iostream>
#include <stdlib.h>
using namespace std;
#define maxqueue 10
struct Queue
{
    int item[maxqueue];
    int front;
    int rear;
};
/**********************************/
void initialise(Queue *q)
{
    q->front = 0;
    q->rear = -1;
}
/**********************************/
bool isempty(Queue *q)
{
    if(q->rear-q->front+ 1 == 0)
        return true;
    else
        return false;
}
/**********************************/
void enqueue(Queue *q, char x)
{
    if(q->rear == maxqueue - 1)
    {
        cout<<"Queue Overflow"<<endl;
        exit(1);
    }
    else
    {
        q->rear++;
        q->item[q->rear]=x;
    }
}
/**********************************/
char dequeue(Queue *q)
{
    if(isempty(q))
    {
        cout<<"Queue Underflow"<<endl;
        exit(1);
    }
    else
    {
        char x=q->item[q->front];
        q->front++;
        return x;
    }
}
int main()
{
    Queue q;
    initialise(&q);
    enqueue(&q, 'A');
    enqueue(&q, 'B');
    enqueue(&q, 'C');
    enqueue(&q, 'D');
    enqueue(&q, 'E');
    enqueue(&q, 'F');
    enqueue(&q, 'G');
    enqueue(&q, 'H');
    enqueue(&q, 'I');
    // enqueue('j');
    // enqueue('k');
    // char x=dequeue();
    // cout<<"Dequeued element: "<<x<<endl;
    // x=dequeue();
    // cout<<"Dequeued element: "<<x<<endl;
    char x=dequeue(&q);
    cout<<"Dequeued element: "<<x<<endl;
    x=dequeue(&q);
    cout<<"Dequeued element: "<<x<<endl;
    x=dequeue(&q);
    cout<<"Dequeued element: "<<x<<endl;
    x=dequeue(&q);
    cout<<"Dequeued element: "<<x<<endl;
    x=dequeue(&q);
    cout<<"Dequeued element: "<<x<<endl;
    return 0;
}