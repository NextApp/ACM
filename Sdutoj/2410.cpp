#include<iostream>
#include<cstdio>
#include<cstring>
#define N 30
using namespace std;
char M[N][N];
int m,n,vis[N][N],OK=0;
int dx[]= {-1,0,1,0,0};
int dy[]= {0,1,0,-1,0};
void print()
{
    if(OK)return ;
    OK=1;
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
            if(vis[i][j]==1)printf(".");
            else if(vis[i][j]==-1)printf("*");
            else printf(" ");
        cout<<endl;
    }
}
int check(int i,int j)
{
    if(i>0&&M[i-1][j])return 0;
    if(i==m-1&&j>0&&M[i][j-1])return 0;
    if(i==m-1&&j==n-1&&M[i][j])return 0;
    return 1;
}
void next(int i,int j);
int  dfs(int i,int j);
void next(int i,int j)
{
    if(j<n)dfs(i,j+1);
    else if(i<m)dfs(i+1,0);
    else print();
}
int dfs(int i,int j)
{
    if(OK)return 0;
    if(vis[i][j])next(i,j);
    else
    {
        int ok=0;
        for(int t=0; t<5; t++)
        {
            int x=i+dx[t],y=j+dy[t];
            if(x>=0&&y>=0&&x<m&&y<n)
            {
                M[x][y]-=1;
                if(M[x][y]<0)ok=1;
            }
        }
        int O=check(i,j);
        if(!ok&&O)
        {
            vis[i][j]=-1;
            next(i,j);
            vis[i][j]=0;
        }
        for(int t=0; t<5; t++)
        {
            int x=i+dx[t],y=j+dy[t];
            if(x>=0&&y>=0&&x<m&&y<n)
                M[x][y]+=1;
        }
        O=check(i,j);
        if(O)
        {
            vis[i][j]=1;
            next(i,j);
            vis[i][j]=0;
        }
    }
}
int main()
{
    int T,id=1;
  //  freopen("1.txt","r",stdin);
    cin>>T;
    while(T--)
    {
        cin>>m>>n;
        for(int i=0; i<m; i++)
            cin>>M[i];
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                M[i][j]-='0';
        memset(vis,0,sizeof(vis));
        cout<<"Case "<<id++<<":"<<endl;
        OK=0;
        dfs(0,0);
    }
    return 0;
}
