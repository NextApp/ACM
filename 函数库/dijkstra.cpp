#include<iostream>
#include<cstdio>
#include<cstring>
#define INF 1000000000
using namespace std;
int n,S,E,id,m,v[1200],M[1200][1200],d[1200];
void Dijkstra()
{
    memset(v,0,sizeof(v));
    for(int i=0; i<n; i++)d[i]=INF;
    d[S]=0;
    for(int i=0; i<n; i++)
    {
        int mm=INF,x;
        for(int y=0; y<n; y++)
            if(!v[y]&&d[y]<mm)
            {
                mm=d[y];
                x=y;
            }
        v[x]=1;
        for(int y=0; y<n; y++)
            if(M[x][y]>=0)d[y]=min(d[y],d[x]+M[x][y]);
    }
    cout<<"Case #"<<id++<<": ";
    if(d[E]<INF)cout<<d[E]<<endl;
    else cout<<"unreachable"<<endl;
}
int main()
{
    freopen("1.txt","r",stdin);
    int T;
    id=1;
    cin>>T;
    while(T--)
    {
        cin>>n>>m>>S>>E;
        memset(M,-1,sizeof(M));
        for(int i=0; i<m; i++)
        {
            int x,y,r;
            cin>>x>>y>>r;
            M[y][x]=M[x][y]=r;
        }
        Dijkstra();
    }
    return 0;
}
