#include <iostream>
#include <stdlib.h>
#include <queue.h>
using namespace std;
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