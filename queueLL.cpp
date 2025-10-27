#include <iostream>
#include <stdlib.h>
#define maxqueue 10
using namespace std;
node * getnode()
{
    node *p;
    p=(node*)malloc(sizeof(struct node));
    return p;
}
struct Queue
{
    node *front;
    node *rear;
}
/**********************************/
void initialise(node *front, node *rear)
{
    q.front = NULL;
    q.rear = NULL;
}
/**********************************/
bool isempty(node *front, node *rear)
{
    if(front == NULL)
        return true;
    else
        return false;
}
/**********************************/
void enqueue(node *front, node *rear, char x)
{
    node *p;
    p=getnode();
    p->info=x;
    p->next=NULL;
    if(rear!=NULL)
        rear->next=p;
    else
        front=p;
    rear=p;
}
/**********************************/
char dequeue(int *front, int *rear)
{
    if(front==NULL)
    {
        cout<<"Queue Underflow"<<endl;
        exit(1);
    }
    else
    {
        p=front;
        front=front->next;
        if(front==NULL)
            rear=NULL;
        x=p->info;
        free(p);
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