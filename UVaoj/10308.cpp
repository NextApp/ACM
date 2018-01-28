#include<iostream>
#include<cstdio>
#include<cstring>
#define N 11000
using namespace std;
struct T
{
    int n,a[N];
} M[N];
int m[N][N],maxv,vis[N];
int dfs(int n)
{
    vis[n]=0;
    int m1=0,m2=0;
    for(int i=0; i<M[n].n; i++)
    {
        int t=M[n].a[i];
        if(vis[t])
        {
            int s=dfs(t)+m[t][n];
            if(s>m1)
            {
                if(m2<m1)m2=m1;
                m1=s;
            }
            else if(s>m2)m2=s;
        }
    }
    if(maxv<m1+m2)maxv=m1+m2;
    return m1;
}
char S[120];
int main()
{
     //freopen("1.txt","r",stdin);
    int a,b,v;
    for(int i=0; i<=10000; i++)M[i].n=0;
    memset(vis,0,sizeof(vis));
    while(gets(S)!=NULL)
    {
        if(S[0]!='\0')
        {
            sscanf(S,"%d%d%d",&a,&b,&v);
            M[a].a[M[a].n++]=b;
            M[b].a[M[b].n++]=a;
            m[a][b]=m[b][a]=v;
            vis[a]=vis[b]=1;
        }
        else
        {
            maxv=0;
            dfs(1);
            cout<<maxv<<endl;
            for(int i=0; i<=10000; i++)M[i].n=0;
            memset(vis,0,sizeof(vis));
        }
    }
    maxv=0;
    dfs(1);
    cout<<maxv<<endl;
    return 0;
}
