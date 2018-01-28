#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define lson l,m,p<<1
#define rson m+1,r,p<<1|1
#define N 100
using namespace std;
int n,x,y,vis[N][N],M[N][N];
struct T
{
    int x,y;
    char c;
} A[N];
int dx[]= {-1,-2,-2,-1,1,2,2,1};
int dy[]= {2,1,-1,-2,-2,-1,1,2};
int ux[]= {0,-1,-1,0,0,1,1,0};
int uy[]= {1,0,0,-1,-1,0,0,1};
int wx[]= {0,0,1,-1};
int wy[]= {1,-1,0,0};
int main()
{
    //  freopen("1.txt","r",stdin);
    while(cin>>n>>x>>y)
    {
        if(!n&&!x&&!y)return 0;
        memset(vis,0,sizeof(vis));
        memset(M,0,sizeof(M));
        vis[x][y]=2;
        for(int i=0; i<n; i++)
        {
            cin>>A[i].c>>A[i].x>>A[i].y;
            vis[A[i].x][A[i].y]=1;
        }
        int u;
        for(int i=0; i<n; i++)
        {
            if(A[i].c=='G')u=i;
            else if(A[i].c=='R')
            {
                int t=A[i].x;
                for(int j=A[i].y+1; j<=9; j++)
                {
                    M[t][j]-=1;
                    if(vis[t][j]==1)break;
                }
                for(int j=A[i].y-1; j>=1; j--)
                {
                    M[t][j]-=1;
                    if(vis[t][j]==1)break;
                }
                t=A[i].y;
                for(int j=A[i].x+1; j<=10; j++)
                {
                    M[j][t]-=1;
                    if(vis[j][t]==1)break;
                }
                for(int j=A[i].x-1; j>=1; j--)
                {
                    M[j][t]-=1;
                    if(vis[j][t]==1)break;
                }
            }
            else if(A[i].c=='H')
            {
                for(int t=0; t<8; t++)
                {
                    int x2=A[i].x+ux[t],y2=A[i].y+uy[t];
                    if(x2>=1&&x2<=10&&y2>=1&&y2<=9&&vis[x2][y2])continue;
                    int x1=A[i].x+dx[t],y1=A[i].y+dy[t];
                    if(x1>=1&&x1<=10&&y1>=1&&y1<=9)M[x1][y1]-=1;
                }
            }
            else if(A[i].c=='C')
            {
                int t=A[i].x,ok=0;
                for(int j=A[i].y+1; j<=9; j++)
                    if(vis[t][j]==1)
                    {
                        ok=j;
                        break;
                    }
                if(ok)
                {
                    for(int j=ok+1; j<=9; j++)
                    {
                        M[t][j]-=1;
                        if(vis[t][j]==1)break;
                    }
                }
                ok=0;
                for(int j=A[i].y-1; j>=1; j--)
                    if(vis[t][j]==1)
                    {
                        ok=j;
                        break;
                    }
                if(ok)
                {
                    for(int j=ok-1; j>=1; j--)
                    {
                        M[t][j]-=1;
                        if(vis[t][j]==1)break;
                    }
                }
                ok=0;
                t=A[i].y;
                for(int j=A[i].x+1; j<=10; j++)
                    if(vis[j][t]==1)
                    {
                        ok=j;
                        break;
                    }
                if(ok)
                {
                    for(int j=ok+1; j<=10; j++)
                    {
                        M[j][t]-=1;
                        if(vis[j][t]==1)break;
                    }
                }
                ok=0;
                for(int j=A[i].x-1; j>=1; j--)
                    if(vis[j][t]==1)
                    {
                        ok=j;
                        break;
                    }

                if(ok)
                {
                    for(int j=ok-1; j>=1; j--)
                    {
                        M[j][t]-=1;
                        if(vis[j][t]==1)break;
                    }
                }
            }
        }
        int ok=0;
        int t=A[u].y;
        for(int i=A[u].x+1; i<=10; i++)
        {
            M[i][t]-=1;
            if(vis[i][t]==2)
            {
                ok=1;
                break;
            }
            if(vis[i][t]==1)break;
        }
        for(int i=A[u].x-1; i>=1; i--)
        {
            M[i][t]-=1;
            if(vis[i][t]==2)
            {
                ok=1;
                break;
            }
            if(vis[i][t]==1)break;
        }
        for(int t=0; t<4; t++)
        {
            int xx=wx[t]+x,yy=wy[t]+y;
            if(xx>=1&&xx<=3&&yy>=4&&yy<=6&&M[xx][yy]>=0)
                ok=1;
        }
        if(!ok)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
