#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int d[10000][6],ok=0;
int a[]= {50,25,10,5,1};
int dp(int S,int cur)
{
    if(d[S][cur]>=0)return d[S][cur];
    if(S<5||cur==4)return 1;
    int s=0;
    for(int i=cur; i<5; i++)
    {
        int v=S;
        if(i==4)
        {
            s++;
            continue;
        }
        while(v>=a[i])
        {
            s+=dp(v-a[i],i+1);
            v-=a[i];
        }
    }
    return d[S][cur]=s;
}
int main()
{
    int n;
    while(cin>>n)
    {
        memset(d,-1,sizeof(d));
        cout<<dp(n,0)<<endl;
    }
    return 0;
}
