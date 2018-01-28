#include<iostream>
#include<cstdio>
#include<cstring>
#define N 2000
using namespace std;
int m,n,OK=0,vis[N][N];
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
char M[N][N];
int dfs(int i,int j,int o)
{
    if(OK)return 0;
    vis[i][j]=o;
    for(int t=0;t<4;t++)
    {
        int x=i+dx[t],y=j+dy[t];
        if(x>=0&&y>=0&&x<m&&y<n&&M[x][y]!='#')
        {
            if(vis[x][y]==-1)dfs(x,y,o);
            else if(vis[x][y]!=o)OK=1;
        }
        else if((x<0||y<0||x>=m||y>=n)&&M[(x+m)%m][(y+n)%n]!='#')
        {
            x+=m,y+=n;
            int s=o+N*dx[t]+dy[t];
            if(vis[x%m][y%n]==-1)dfs(x%m,y%n,s);
            else if(vis[x%m][y%n]!=s)OK=1;
        }
    }
}
int main()
{
    //freopen("1.txt","r",stdin);
    while(cin>>m>>n)
    {
        for(int i=0; i<m; i++)
            cin>>M[i];
        memset(vis,-1,sizeof(vis));
        int ok=0;
        OK=0;
        for(int i=0; i<m&&!ok; i++)
            for(int j=0; j<n; j++)
                if(M[i][j]=='S')
                {
                    dfs(i,j,N*N);
                    ok=1;
                    break;
                }
        if(OK)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}
