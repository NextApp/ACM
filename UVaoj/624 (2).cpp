#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int m,n,a[30],A[30],goal,v[30],o;
void print_subset(int cur)
{
    int sum=0;
    for(int i=0;i<cur;i++)
        sum+=a[A[i]];
    if(sum>m)return ;
    else if(goal<sum)
    {
        memcpy(v,A,sizeof(A));
        o=cur;
        goal=sum;
    }
    int s=cur?A[cur-1]+1:0;
    for(int i=s;i<n;i++)
    {
        A[cur]=i;
        print_subset(cur+1);
    }
}
int main()
{
    freopen("1.txt","r",stdin);
    while(cin>>m>>n)
    {
        for(int i=0; i<n; i++)
            cin>>a[i];
        for(int i=0;i<n;i++)A[i]=i;
            goal=0;
        print_subset(0);
        for(int i=0;i<o;i++)
        cout<<a[v[i]]<<' ';
        cout<<"sum:"<<goal<<endl;
    }
}
