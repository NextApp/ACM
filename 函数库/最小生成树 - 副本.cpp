#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#define N 100
#define MAX 1000000
using namespace std;
int M[N][N],n,ss=0,S[N];
typedef struct
{
    int ix,iy;
} G;
struct cmp
{
    bool operator()(const G &a,const G &b)
    {
        return M[a.ix][a.iy]  > M[b.ix][b.iy] ;
    }
};
void read()
{
    int a,b,l,m;
    memset(M,0,sizeof(M));
    cin>>n>>m;
    for (int i=0; i<m; i++)
    {
        cin>>a>>b>>l;
        M[a][b]=l;
        M[b][a]=l;
    }
}
void  MiniSpanTree_PRIM(int u)
{
    G p[N];
    G *arr=new G[N*N];
    priority_queue<G,vector<G>,cmp>Q;
    int ix,min=MAX,mm=0,k=1;
    S[k-1]=u;
    while(k<n)
    {
        for (int i=0; i<n; i++)
        {
            if (M[u][i])
            {
                G uu;
                uu.ix=u,uu.iy=i;
                Q.push(uu);
            }
        }
        while(!Q.empty()&&!M[Q.top().ix][Q.top().iy])Q.pop();
        int m=Q.top().iy;
        p[ss].ix=Q.top().ix,p[ss++].iy=m;
        u=m;
        for(int i=0; i<k; i++)M[S[i]][m]=0,M[m][S[i]]=0;
        S[k]=u;
        k++;
    }
    for(int i=0; i<ss; i++)
    {
        cout<<p[i].ix<<' '<<p[i].iy<<endl;
    }
}
int main()
{
    freopen("1.txt","r",stdin);
    read();
    MiniSpanTree_PRIM(0);
}
