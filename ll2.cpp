#include<iostream>
#include<stdlib.h>
using namespace std;
struct node
{
    char info;
    struct node *next;
};
struct node *start;
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
    int c=0;
    node *p=start;
    while(p!=NULL)
    {
        c++;
        cout<<p->info;
        p=p->next;
    }
    cout<<c;
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
}