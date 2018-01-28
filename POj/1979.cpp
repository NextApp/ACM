#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int num,vis[25][25];
int xt[]= {-1,0,1,0};
int yt[]= {0,1,0,-1};
int m,n;
char M[25][25];
int dfs(int i,int j)
{
    vis[i][j]=1;
    num++;
    for(int t=0; t<4; t++)
    {
        int x=i+xt[t],y=j+yt[t];
        if(x>=0&&y>=0&&x<n&&y<m&&!vis[x][y]&&M[x][y]=='.')
            dfs(x,y);
    }
}
int main()
{
   // freopen("1.txt","r",stdin);
    while(cin>>m>>n)
    {
        if(!m&&!n)break;
        else
        {
            for(int i=0; i<n; i++)
                cin>>M[i];
            num=0;
            memset(vis,0,sizeof(vis));
            for(int i=0; i<n&&!num; i++)
                for(int j=0; j<m&&!num; j++)
                {
                    if(M[i][j]&&M[i][j]=='@')
                        dfs(i,j);
                }
            cout<<num<<endl;
        }

    }
    return 0;
}
