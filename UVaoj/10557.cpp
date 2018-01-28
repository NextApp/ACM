#include<iostream>
#include<cstdio>
#include<cstring>
#define N 105
#define INF 100000000
using namespace std;
struct T
{
    int v,n,a[N];
} node[N];
int d[N],n,k,M[N][N],vis[N][N];
int dfs(int cur)
{
    for(int i=0; i<n; i++)
        if(vis[i][cur]==1)
        {
            vis[i][cur]=-1;
            dfs(i);
        }
}
int relax(int i,int j)
{
    if(d[j]>M[i][j]+d[i]&&M[i][j]+d[i]<0)
        d[j]=M[i][j]+d[i];
}
int Bellman()
{
    for(int i=1; i<n; i++)
        d[i]=INF;
    d[0]=-100;
    for(int i=1; i<n; i++)
        for(int j=0; j<n; j++)
            for(int k=0; k<n; k++)
                if(j!=k&&vis[j][k]==-1)relax(j,k);
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            if(i!=j&&vis[i][j]==-1&&M[i][j]+d[i]<0)
                if(d[j]>d[i]+M[i][j])
                    return -1;
    return 0;
}
int main()
{
    freopen("1.txt","r",stdin);
    while(cin>>n)
    {
        if(n<0)break;
        else
        {
            memset(M,0,sizeof(M));
            memset(vis,0,sizeof(vis));
            for(int i=0; i<n; i++)
            {
                cin>>node[i].v>>node[i].n;
                for(int j=0; j<node[i].n; j++)
                    cin>>node[i].a[j];
            }
            for(int i=0; i<n; i++)
                for(int j=0; j<node[i].n; j++)
                {
                    int m=node[i].a[j]-1;
                    M[i][m]=-node[m].v;
                    vis[i][m]=1;
                }
            dfs(n-1);
            int l=Bellman();
            if(!l&&d[n-1]>=0)cout<<"hopeless"<<endl;
            else cout<<"winnable"<<endl;
        }
    }
    return 0;
}
