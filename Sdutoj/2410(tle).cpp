#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char M[50][50];
int vis[50][50];
int m,n,k;
int dx[10]= {0,1,0,-1,0};
int dy[10]= {-1,0,1,0,0};
struct T
{
    int i,j;
} q[500];
int check()
{
    int ok=1;
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
            if(!vis[i][j])
            {
                q[k].i=i,q[k++],j=j;
                ok=0;
            }
    return ok;
}
int judge(int i,int j)
{
    int num=M[i][j]-'0';
    int s=0,l=0,d=0;
    for(int t=0; t<5; t++)
    {
        int x=i+dy[t],y=j+dx[t];
        if(x>=0&&y>=0&&x<m&&y<n)
        {
            d++;
            if(vis[x][y]==1)s++;
            else if(vis[x][y]==-1)l++;
        }
    }
    int ok=0;
    if(d-s-l==0)
    {
        if(num!=l)return -1;
        else return 0;
    }
    if(num==l)
    {
        for(int t=0; t<5; t++)
        {
            int x=i+dy[t],y=j+dx[t];
            if(x>=0&&y>=0&&x<m&&y<n&&!vis[x][y])vis[x][y]=1;
        }
        ok=1;
    }
    if(d-s==num)
    {
        for(int t=0; t<5; t++)
        {
            int x=i+dy[t],y=j+dx[t];
            if(x>=0&&y>=0&&x<m&&y<n&&!vis[x][y])vis[x][y]=-1;
        }
        ok=1;
    }
    return ok;
}
int Judge()
{
    int ok;
    for(int t=0; t<m*n; t++)
    {
        ok=0;
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
            {
                int s=judge(i,j);
                if(s==-1)return -1;
                else ok=s;
            }
        if(!ok)break;
    }
    return ok;
}
int main()
{
   // freopen("1.txt","r",stdin);
    int T,id=1;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&m,&n);
        for(int i=0; i<m; i++)
            scanf("%s",M[i]);
        memset(vis,0,sizeof(vis));
        Judge();
        k=0;
        check();
        int v[50][50];
        while(k)
        {
            int i=q[k-1].i,j=q[k-1].j;
            if(vis[i][j])continue;
            memcpy(v,vis,sizeof(vis));
            vis[i][j]=-1;
            if(Judge()==-1)
            {
                memcpy(vis,v,sizeof(v));
                vis[i][j]=1;
                Judge();
            }
            k=0;
            check();
        }
        printf("Case %d:\n",id++);
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
                if(vis[i][j]==1)printf(".");
                else printf("*");
            printf("\n");
        }
    }
    return 0;
}
