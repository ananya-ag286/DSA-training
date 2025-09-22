#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cout<<"enter no of elements in 1st array";
    cin>>n;
    vector<int>A(n);
    cout<<"enter elements";
    int r=0;
    for (int i=0; i<n; i++)
    {
        cin>>A[i];
        if (r<A[i])
        {
            r=A[i];
        }
    }
    vector<int>B(r+1);
    B[r+1]={0};
    for (int i=0;i<n;i++)
    {
        B[A[i]]=1;
    }
    for (int i=1; i<=r; i++){
        if (B[i]==0){
            cout<<(i);
        }
    }
}