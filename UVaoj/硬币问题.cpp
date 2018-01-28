#include<iostream>
#include<cstdio>
#include<cstring>
#define INF -1
#define DNF 10000000
using namespace std;
int a[10],S,n,d[1000];
int maxdp(int S)
{
    if(!S)return 0;
    else if(d[S]>=0)return d[S];
    int m=INF;
    for(int i=0; i<n; i++)
        if(S-a[i]>=0)
        {
            int c=maxdp(S-a[i]);
            if(c==INF)continue;
            m=max(m,c+1);
        }
    return d[S]=m;
}
int mindp(int S)
{
    if(!S)return 0;
    else if(d[S]>=0)return d[S];
    int m=DNF;
    for(int i=0; i<n; i++)
        if(S-a[i]>=0)
        {
            int c=mindp(S-a[i]);
            if(c==DNF)continue;
            m=min(m,c+1);
        }
    return d[S]=m;
}
int main()
{
    freopen("1.txt","r",stdin);
    while(cin>>n>>S)
    {
        for(int i=0; i<n; i++)
            cin>>a[i];
        memset(d,-1,sizeof(d));
        int m=maxdp(S);
        if(m==INF)cout<<"impossible"<<endl;
        else cout<<m<<endl;
        memset(d,-1,sizeof(d));
        m=mindp(S);
        if(m==DNF)cout<<"impossible"<<endl;
        else cout<<m<<endl;
        cout<<endl;
    }
    return 0;
}
