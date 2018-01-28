#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int id=0;
void print_subset(int n,int *A,int cur)
{
    for(int i=0;i<cur;i++)
        cout<<A[i];
    cout<<endl;
    int s=cur?A[cur-1]+1:0;
    for(int i=s;i<n;i++)
    {
        A[cur]=i;
        print_subset(n,A,cur+1);
        cout<<"***"<<id++<<"((("<<i<<endl;
    }
}
int main()
{
    int A[100],n;
    while(cin>>n)
    {
        for(int i=1;i<=n;i++)
            A[i]=i;
        print_subset(n,A,0);
    }
    return 0;
}
