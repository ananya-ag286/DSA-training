#define stacksize 100
struct Stack
{
    int item[stacksize];
    int top;
};
/**********************************/
void initialize(Stack *fs)
{
    fs->top=-1;
}
/**********************************/
bool isEmpty(Stack *fs)
{
    if(fs->top==-1)
        return true;
    else
        return false;
}
/**********************************/
void push(Stack *fs,int x)
{
    if(fs->top==99)
    {
        cout<<"Stack Overflow"<<endl;
        exit(1);
    }
    else
    {
        fs->top++;
        fs->item[s.top]=x;
    }
}
/**********************************/
int pop(Stack *fs)
{
    int x;
    if(isEmpty())
    {
        cout<<"Stack Underflow"<<endl;
        exit(1);
    }
    else
    {
        x=fs->item[s.top];
        fs->top--;
        return x;
    }
}
/**********************************/