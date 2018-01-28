#include<iostream>
#include<cstdio>
#include<cstring>
#define N 100
#define INF 100000000
using namespace std;
struct T
{
    int x,y;
} A[N];
int n,d[N][N],dt[N][N];
int dp(int i,int j)
{
    if(j<=i)return 0;
    if(d[i][j]<INF)return d[i][j];
    int m=INF,s=i;
    for(int t=i; t<j; t++)
    {
        int d=m;
        m=min(m,dp(i,t)+dp(t+1,j)+A[i].x*A[t].y*A[j].y);
        if(m!=d)s=t;
    }
    dt[i][j]=s;
    return d[i][j]=m;
}
int print(int i,int j)
{
    if(i>=j)
    {
        cout<<'A'<<i+1;
        return 0;
    }
    if(i<=dt[i][j])
    {
        cout<<'(';
        print(i,dt[i][j]);
        cout<<' '<<'x'<<' ';
    }
    if(j>=dt[i][j]+1)
    {
        print(dt[i][j]+1,j);
        cout<<')';
    }
}
int main()
{
    freopen("1.txt","r",stdin);
    int id=1;
    while(cin>>n&&n)
    {
        for(int i=0; i<n; i++)
            cin>>A[i].x>>A[i].y;
        for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        d[i][j]=INF;
        dp(0,n-1);
        cout<<"Case "<<id++<<": ";
        print(0,n-1);
        cout<<endl;
    }
    return 0;
}
