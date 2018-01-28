#include<iostream>
#include<cstring>
#include<cstdio>
#define N 100
using namespace std;
int dx[]= {-1,1,0,0};
int dy[]= {0,0,-1,1};
int vis[N][N],m,n;
char M[N][N];
int dfs(int i,int j)
{
    vis[i][j]=1;
    for(int t=0; t<4; t++)
    {
        int x=i+dx[t],y=j+dy[t];
        if(x>=0&&x<m&&y>=0&&y<n&&M[x][y]=='#'&&!vis[x][y])
            dfs(x,y);
    }
}
int main()
{
    //  freopen("1.txt","r",stdin);
    while(cin>>m>>n)
    {
        for(int i=0; i<m; i++)
            cin>>M[i];
        memset(vis,0,sizeof(vis));
        int l=0,num=2,O[10];
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                if(M[i][j]=='#')
                {
                    l++;
                    if(num==1)continue;
                    int s=0;
                    memset(O,0,sizeof(O));
                    for(int t=0; t<4; t++)
                    {
                        int x=i+dx[t],y=j+dy[t];
                        if(x>=0&&x<m&&y>=0&&y<n&&M[x][y]=='#')s++,O[t]=1;
                    }
                    memset(vis,0,sizeof(vis));
                    int u=0;
                    vis[i][j]=1;
                    for(int t=0; t<4; t++)
                        if(O[t]&&!vis[i+dx[t]][j+dy[t]])
                        {
                            dfs(i+dx[t],j+dy[t]);
                            u++;
                        }
                    if(u>=2)num=1;
                    num=min(s,num);
                }
        if(l<=2)cout<<-1<<endl;
        else cout<<num<<endl;
    }
    return 0;
}
