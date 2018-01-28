#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int ix[]= {-1,-1,0,0,1,1};
int iy[]= {-1,0,-1,1,0,1};
int n,OK,vis[300][300],id=1;
char M[300][300];
int dfs(int i,int j)
{
    vis[i][j]=1;
    if(j==n-1)OK=1;
    if(!OK)
    {
        for(int t=0; t<6; t++)
        {
            int dx=ix[t]+i,dy=iy[t]+j;
            if(dx>=0&&dx<n&&dy>=0&&dy<n&&!vis[dx][dy]&&M[i][j]==M[dx][dy])
                dfs(dx,dy);
        }
    }
}
int main()
{
    while(cin>>n)
    {
        if(!n)break;
        else
        {
            for(int i=0; i<n; i++)
                cin>>M[i];
            OK=0;
            memset(vis,0,sizeof(vis));
            for(int i=0; i<n; i++)
                if(M[i][0]=='w'&&!OK)dfs(i,0);
            cout<<id++<<' ';
            if(OK)cout<<'W'<<endl;
            else cout<<'B'<<endl;
        }
    }
    return 0;
}
