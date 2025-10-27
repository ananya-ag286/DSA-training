#include <iostream>
#include <stdlib.h>
using namespace std;
struct node
{
    char info;
    struct node *prev, *next;
};
node *leftt, *rightt;
/**********************************/
node * getnode()
{
    node *p;
    p=(node*)malloc(sizeof(struct node));
    return p;
}
void insertleft(char x)
{
    node *p;
    p=getnode();
    p->info=x;
    p->prev=NULL;
    p->next=leftt;
    if(leftt!=NULL)
        leftt->prev=p;
    else
        rightt=p;
    leftt=p;
}
/**********************************/
void insertright(char x)
{
    node *p;
    p=getnode();
    p->info=x;
    p->next=NULL;
    p->prev=rightt;
    if(rightt!=NULL)
        rightt->next=p;
    else
        leftt=p;
    rightt=p;
}
void traverse()
{
    node *temp;
    temp=leftt;
    while(temp!=NULL)
    {
        cout<<temp->info<<" ";
        temp=temp->next;
    }

}
int main()
{
    leftt=NULL;
    rightt=NULL;
    insertright('A');
    insertright('B');
    insertright('C');
    insertright('D');
    insertright('E');
    traverse();
    return 0;
}