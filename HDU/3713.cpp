#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define N 30000
using namespace std;
int dx[]= {1,0,0,-1};
int dy[]= {0,-1,1,0};
int a[10][10],b[10][10];
int q[N],w[N],s[N],n=6,road[N],vis[10][10][10][10];
char C[]= {'D','L','R','U'},O[N];
int init(int c[10][10])
{
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            if(c[i][j]&32)return i*n+j;
}
int d[]={2,1,4,8};
int check(int c[10][10],int x,int y,int t)
{
    int xx=dx[t]+x,yy=dy[t]+y;
    if(c[x][y]&d[t])return 0;
    if(xx<0||yy<0||xx>=n||yy>=n||!(c[xx][yy]&16))return -1;
    return 1;
}
int bfs(int ra,int rb)
{
    int rear=1,front=0;
    memset(s,-1,sizeof(s));
    memset(vis,0,sizeof(vis));
    q[front]=ra;
    w[front]=rb;
    while(front<rear)
    {
        int u1=q[front];
        int u2=w[front];
        int x1=u1/n,y1=u1%n;
        int x2=u2/n,y2=u2%n;
        if(!front)vis[x1][y1][x2][y2]=1;
        if(a[x1][y1]&64&&b[x2][y2]&64)
        {
            if(!front)
            {
                printf("\n");
                return -1;
            }
            return front;
        }
        for(int t=0; t<4; t++)
        {
            int l1=check(a,x1,y1,t);
            int l2=check(b,x2,y2,t);
            int ok=0;
            int x=x1+dx[t],y=y1+dy[t];
            int x0=x2+dx[t],y0=y2+dy[t];
            if(l1==1&&l2==1)ok=1;
            else if(l1==1&&!l2)x0=x2,y0=y2,ok=1;
            else if(!l1&&l2==1)x=x1,y=y1,ok=1;
            if(ok&&!vis[x][y][x0][y0])
            {
                vis[x][y][x0][y0]=vis[x1][y1][x2][y2]+1;
                road[rear]=t;
                q[rear]=x*n+y;
                s[rear]=front;
                w[rear++]=x0*n+y0;
            }
        }
        front++;
    }
    return 0;
}
int main()
{
   // freopen("1.txt","r",stdin);
   // freopen("2.txt","w",stdout);
    int T;
    scanf("%d",&T);
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            scanf("%d",&a[i][j]);
    while(--T)
    {
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                scanf("%d",&b[i][j]);
        int ok=bfs(init(a),init(b));
        if(ok>0)
        {
            int i=0;
            while(s[ok]!=-1)
            {
                O[i++]=C[road[ok]];
                ok=s[ok];
            }
            for(int j=i-1; j>=0; j--)
                printf("%c",O[j]);
            printf("\n");
        }
        else if(!ok)printf("-1\n");
        memcpy(a,b,sizeof(b));
    }
    return 0;
}
