#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int a[1001000],n;
int Lowbit(int x)
{
    return x&(-x);
}
int Sum(int s)
{
    int sum=0;
    while(s)
    {
        sum+=a[s];
        s-=Lowbit(s);
    }
    return sum;
}
int Update(int s,int num)
{
    while(s<=n)
    {
        a[s]+=num;
        s+=Lowbit(s);
    }
}
int main()
{
    int T,id=1;
    cin>>T;
    while(T--)
    {
        int sum=0;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            int m;
            cin>>m;
            sum+=m;
            a[i]=sum-Sum(i-Lowbit(i));
        }
        char m[120];
        int x,y;
        cout<<"Case "<<id++<<":"<<endl;
        while(cin>>m)
        {
            if(!strcmp("End",m))break;
            cin>>x>>y;
            if(!strcmp("Query",m))cout<<Sum(y)-Sum(x-1)<<endl;
            else if(!strcmp("Add",m))Update(x,y);
            else Update(x,-y);
        }
    }
    return 0;
}
