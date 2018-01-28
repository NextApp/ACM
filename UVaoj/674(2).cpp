#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int d[10000][6],ok=0;
int a[]= {50,25,10,5,1};
int dp(int S,int cur)
{
    if(d[S][cur]>=0)return d[S][cur];
    if(S<5||cur==4)return d[S][cur]=1;
    int s=0;
    for(int i=cur; i<5; i++)
        if(S-a[i]>=0)s+=dp(S-a[i],i);
    return d[S][cur]=s;
}
int main()
{
    int n;
    memset(d,-1,sizeof(d));
    for(int i=0;i<=7498;i++)
    if(d[i][0]<0)dp(i,0);
    while(cin>>n)
    {
        cout<<d[n][0]<<endl;
    }
    return 0;
}
