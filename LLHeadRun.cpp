#include<iostream>
#include<stdlib.h>
#include "LLHeader.h"
using namespace std;
void traverse(node *start)
{
    node *p=start;
    while(p!=NULL)
    {
        cout<<p->info;
        p=p->next;
    }
}
int countnode(node *start)
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
void MiddleElement1(node *start)
{
    int c=countnode(start);
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
void MiddleElement2(node *start)
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
    struct node *start;
    start=NULL;
    insbeg(&start,'A');
    insbeg(&start,'B');
    insbeg(&start,'C');
    insbeg(&start,'D');
    insbeg(&start,'E');
    insbeg(&start,'F');
    insend(&start,'X');
    insend(&start,'Y');
    insend(&start,'Z');
    traverse(start);
    cout<<"\n\ncount="<<countnode(start);
    MiddleElement1(start);
    MiddleElement2(start);
    insaft(start->next->next,'P');
    cout<<"\n\nAfter Insertion\n";
    traverse(start);

    delbeg(&start);
    delend(&start);
    delaft(start->next);
    cout<<"\n\nAfter Deletion\n";
    traverse(start);
    return 0;

}
