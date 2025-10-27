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
    orderedinsertion(&start,'Q');
    orderedinsertion(&start,'G');
    orderedinsertion(&start,'M');
    orderedinsertion(&start,'T');
    orderedinsertion(&start,'C');
    traverse(start);
    return 0;

}