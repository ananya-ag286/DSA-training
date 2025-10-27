//LinkedListHeader file
struct node
{
    char info;
    struct node *next;
};
node * getnode()
{
    node *p;
    p=(node*)malloc(sizeof(struct node));
    return p;
}
/***************************/
void insbeg(node **start, char x)
{
    node *p;
    p=getnode();
    p->info=x;
    p->next=*start;
    *start=p;
}
/***************************/
void insend(node **start, char x)
{
    node *q=*start;
    node *p=getnode();
    p->info=x;
    p->next=NULL;
    while(q->next!=NULL)
        q=q->next;
    q->next=p;

}
/***************************/
void insaft(node *q, char x)
{
    node *p,*r;
    p=getnode();
    p->info=x;
    r=q->next;
    q->next=p;
    p->next=r;
}
/***************************/
char delbeg(node **start, char x)
{
    node *p;
    p=*start;
    *start=(*start)->next;
    x=p->info;
    free(p);
    return x;
}
/***************************/
char delend(node **start, char x)
{
    node *p,*q;
    p=*start;
    q=NULL;
    while(p!=NULL)
    {
        q=p;
        p=p->next;
    }
    x=p->info;
    q->next=NULL;
    free(p);
    return x;
}
/***************************/
char delaft(node *q, char x)
{
    node *p, *r;
    p=q->next;
    r=p->next;
    q->next=r;
    x=p->info;
    free(p);
    return x;
}
/***************************/
orderedinsertion(node **start, int x)
{
    node *p,*q;
    p=*start;
    q=NULL;
    while(p!=NULL && x>p->info)
    {
        q=p;
        p=p->next;
    }
    if(q==NULL)
        insbeg(&(*start),x);
    else
        insaft(&q,x);
}
/***************************/
revtraverse(node *p)
{
    if(p!=NULL)
    {
        revtraverse(p->next);
        cout<<p->info<<" ";
    }
}
/***************************/
node *mergelinkedlist(node *start1, node *start2)
{
    node *p,*q,*start3;
    p=start1;
    q=start2;
    start3=NULL;
    while(p!=NULL && q!=NULL)
    {
        if(p->info < q->info)
        {
            insbeg(&start3,p->info);
            p=p->next;
        }
        else
        {
            insbeg(&start3,q->info);
            q=q->next;
        }
    }
    while(p!=NULL)
    {
        insbeg(&start3,p->info);
        p=p->next;
    }
    while(q!=NULL)
    {
        insbeg(&start3,q->info);
        q=q->next;
    }
    revtraverse(start3);
    return start3;
}
/***************************/

