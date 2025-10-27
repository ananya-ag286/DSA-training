#include <iostream>
#include <stdlib.h>
using namespace std;
int n;
void arrayinsertion(int a[], int i, int n, int x)
{
    for(int j=n;j>i;j--)
        a[j]=a[j-1];
    a[i]=x;
    n=n+1;
}
int arraydeletion(int a[], int i, int n)
{
    int x=a[i];
    for(int j=i;j<n;j++)
        a[j]=a[j+1];
    n=n-1;
    return x;
}
void arrayinsertiondec(int a[], int i, int n, int x)
{
    int j;
    for(j=n;j>i;j--)
        a[j]=a[j-1];
    a[i]=x;
    n=n+1;
}
int enqueue(int a[], int n, int x)
{
    int i=0;
    while(i<n && x>=a[i])
        i++;
    arrayinsertion(a,i,n,x);
}
int dequeue(int a[], int n)
{
    int x=arraydeletion(a,0,n);
    return x;
}
int enqueuedecreasing(int a[], int n, int x)
{
    int i=0;
    while(i<n && x<=a[i])
        i++;
    arrayinsertiondec(a,i,n,x);
}
int dequeuedecreasing(int a[], int n)
{
    int x=a[n-1];
    n=n-1;
    return x;
}
void reverse(int a[],int n)
{
    for(int i=n-1;i>(n-1)/2;i--)
    {
        int x=a[i];
        a[i]=a[n-i-1];
        a[n-i-1]=x;
    }
}
int main()
{
    cin>>n;
    int a[100];
    for(int i=0;i<n;i++)
        cin>>a[i];
    int x;
    cin>>x;
    enqueue(a,n,x);
    for(int i=0;i<=n;i++)
        cout<<a[i]<<" ";
    int y=dequeue(a,n);
    cout<<endl<<y<<endl;
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    reverse(a,n);
    cout<<endl;
    int m;
    cin>>m;
    enqueuedecreasing(a,n,m);
    cout<<endl;
    reverse(a,n);
    for(int i=0;i<=n;i++)
        cout<<a[i]<<" ";
    reverse(a,n);
    int z=dequeuedecreasing(a,n);
    cout<<endl<<z<<endl;
    reverse(a,n);
    for(int i=0;i<n-1;i++)
        cout<<a[i]<<" ";
}