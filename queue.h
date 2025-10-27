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