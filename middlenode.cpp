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
int countnode()
{
    int c=0;
    node *p=start;
    while(p!=NULL)
    {
        c++;
        p=p->next;
    }
    return c;
}
void MiddleElement1()
{
    int c=countnode();
    int i=1;
    node *p=start;
    for(int i=1;i<c/2;i++)
    {
        p=p->next;
    }
    if(c%2!=0)
        p=p->next;
    cout<<"\n\nMiddle Element is: "<<p->info;
}
void MiddleElement2()
{
    node *t, *r;
    t=start;
    r=start->next;
    while(r!=NULL && r->next!=NULL)
    {
        t=t->next;
        r=r->next;
        r=r->next;
    }
    cout<<"\n\nMiddle Element is: "<<t->info;
}
int main()
{
    start=NULL;
    insbeg('A');
    insbeg('B');
    insbeg('C');
    insbeg('D');
    insbeg('E');
    insend('X');
    insend('Y');
    insend('Z');
    traverse();
    int c=countnode();
    cout<<c;
    MiddleElement1();
    MiddleElement2();
    return 0;
}
