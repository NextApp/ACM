#include<iostream>
#include<cstdio>
#include<cstring>
#define N 10
using namespace std;
int dx[]= {-1,0,1,0,0};
int dy[]= {0,1,0,-1,0};
int m=5,n=6,a[N][N],vis[N][N],s=0,M[N][N];
void dfs(int i,int j);
int OK=0;
void judge()
{
    if(!OK)
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n-1; j++)
                cout<<vis[i][j]<<' ';
            cout<<vis[i][n-1]<<endl;
        }
    OK=1;
}
void gonext(int i,int j)
{
    if(j<5)dfs(i,j+1);
    else if(i<4)dfs(i+1,0);
    else judge();
}
void dfs(int i,int j)
{
    if(OK)return;
    int ok=1;
    int x=i-1,y=j;
    if(x>=0&&x<m&&y>=0&&y<n&&!a[x][y])ok=0;
    if(i==4)
    {
        x=i,y=j-1;
        if(y>=0&&!a[x][y])ok=0;
    }
    if(i==4&&j==5&&!a[i][j])ok=0;
    if(ok)
    {
        vis[i][j]=1;
        for(int t=0; t<5; t++)
        {
            int x=dx[t]+i,y=dy[t]+j;
            if(x>=0&&x<m&&y>=0&&y<n)
                a[x][y]=!a[x][y];
        }
        gonext(i,j);
        for(int t=0; t<5; t++)
        {
            int x=dx[t]+i,y=dy[t]+j;
            if(x>=0&&x<m&&y>=0&&y<n)
                a[x][y]=!a[x][y];
        }
        vis[i][j]=0;
    }
    x=i-1,y=j;
    if(x>=0&&x<m&&y>=0&&y<n)
    {
        if(a[x][y])return;
    }
    if(i==4)
    {
        x=i,y=j-1;
        if(y>=0&&a[x][y])return;
    }
    if(i==4&&j==5&&a[i][j])return;
    gonext(i,j);
}
int main()
{
    freopen("1.txt","r",stdin);
    int T,id=1;
    cin>>T;
    while(T--)
    {
        cout<<"PUZZLE #"<<id++<<endl;
        OK=0;
        memset(vis,0,sizeof(vis));
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                cin>>a[i][j];
        dfs(0,0);
    }
    return 0;
}
