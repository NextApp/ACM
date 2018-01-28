#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int end,n,tot,C[30],vis[25],V[25],M[25][25];
int dfs(int cur,int k)
{
    if(cur==end)
    {
        tot++;
        for(int j=0; j<k-1; j++)
            cout<<C[j]<<' ';
        cout<<end<<endl;
    }
    else for(int i=1; i<=n; i++)
        {
            if(!vis[i]&&V[i]&&M[cur][i])
            {
                vis[i]=1;
                C[k]=i;
                dfs(i,k+1);
                vis[i]=0;
            }
        }
}
int Dfs(int cur)
{
    for(int i=1; i<=n; i++)
        if(!V[i]&&M[cur][i])
        {
            V[i]=1;
            Dfs(i);
        }
}
int main()
{
    freopen("1.txt","r",stdin);
    int id=1;
    while(cin>>end)
    {
        n=0;
        tot=0;
        int a,b;
        memset(M,0,sizeof(M));
        memset(vis,0,sizeof(vis));
        memset(V,0,sizeof(V));
        while(cin>>a>>b)
        {
            if(!a&&!b)break;
            else
            {
                M[a][b]=M[b][a]=1;
                n=a>n?a:n;
                n=b>n?b:n;
            }
        }
        cout<<"CASE "<<id++<<":"<<endl;
        vis[1]=1;
        V[end]=1;
        V[1]=1;
        C[0]=1;
        Dfs(end);
        dfs(1,1);
        cout<<"There are "<<tot<<" routes from the firestation to streetcorner "<<end<<"."<<endl;
    }
    return 0;
}
