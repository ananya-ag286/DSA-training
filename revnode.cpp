#include<iostream>
#include<stdlib.h>
using namespace std;
struct node
{
    char info;
    struct node *next;
};

struct node *start;
/**********************************/
node * getnode()
{
    node *p;
    p=(node*)malloc(sizeof(struct node));
    return p;
}
void insbeg(char x)
{
    node *p;
    p=getnode();
    p->info=x;
    p->next=start;
    start=p;
}
void insend(char x)
{
    node *q=start;
    node *p=getnode();
    p->info=x;
    p->next=NULL;
    while(q->next!=NULL)
        q=q->next;
    q->next=p;

}
void traverse()
{
    node *p=start;
    while(p!=NULL)
    {
        cout<<p->info;
        p=p->next;
    }
}
void reverse()
{
    node *p=NULL;
    node *c=start;
    node *n=c->next;
    while(c!=NULL)
    {
        c->next=p;
        p=c;
        c=n;
        if(n!=NULL)
            n=n->next;
    }
    start=p;
}
int main()
{
    start=NULL;
    insbeg('A');
    insbeg('B');
    insbeg('C');
    insbeg('D');
    insbeg('E');
    insbeg('F');
    insend('X');
    insend('Y');
    insend('Z');
    traverse();
    reverse();
    cout<<"\nAfter Reversing\n";
    traverse();
}