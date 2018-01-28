#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int q[12000],start,end,vis[12000];
int cal(int a,int b,int c,int d)
{
    return a*1000+b*100+c*10+d;
}
int resolve(int n,int &a,int &b,int &c,int &d)
{
    a=n/1000;
    b=n/100%10;
    c=n/10%10;
    d=n%10;
}
int C(int a)
{
    return a==0?9:a-1;
}
int bfs()
{
    int rear=1,front=0;
    q[front]=start;
    int a,b,c,d,n,s;
    while(front<rear)
    {
        n=q[front++];
        resolve(n,a,b,c,d);
        s=cal((a+1)%10,b,c,d);
        if(vis[s]==-1)
        {
            vis[s]=vis[n]+1;
            if(s==end)return vis[s];
            q[rear++]=s;
        }
        s=cal(a,(b+1)%10,c,d);
        if(vis[s]==-1)
        {
            vis[s]=vis[n]+1;
            if(s==end)return vis[s];
            q[rear++]=s;
        }
        s=cal(a,b,(c+1)%10,d);
        if(vis[s]==-1)
        {
            vis[s]=vis[n]+1;
            if(s==end)return vis[s];
            q[rear++]=s;
        }
        s=cal(a,b,c,(d+1)%10);
        if(vis[s]==-1)
        {
            vis[s]=vis[n]+1;
            if(s==end)return vis[s];
            q[rear++]=s;
        }
        s=cal(C(a),b,c,d);
        if(vis[s]==-1)
        {
            vis[s]=vis[n]+1;
            if(s==end)return vis[s];
            q[rear++]=s;
        }
        s=cal(a,C(b),c,d);
        if(vis[s]==-1)
        {
            vis[s]=vis[n]+1;
            if(s==end)return vis[s];
            q[rear++]=s;
        }
        s=cal(a,b,C(c),d);
        if(vis[s]==-1)
        {
            vis[s]=vis[n]+1;
            if(s==end)return vis[s];
            q[rear++]=s;
        }
        s=cal(a,b,c,C(d));
        if(vis[s]==-1)
        {
            vis[s]=vis[n]+1;
            if(s==end)return vis[s];
            q[rear++]=s;
        }
    }
    return -1;
}
int main()
{
    freopen("1.txt","r",stdin);
    int T,a,b,c,d,m;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d%d",&a,&b,&c,&d);
        memset(vis,-1,sizeof(vis));
        start=cal(a,b,c,d);
        vis[start]=0;
        scanf("%d%d%d%d",&a,&b,&c,&d);
        end=cal(a,b,c,d);
        scanf("%d",&m);
        for(int i=0; i<m; i++)
        {
            scanf("%d%d%d%d",&a,&b,&c,&d);
            vis[cal(a,b,c,d)]=1;
        }
        int ok=0;
        if(start!=end)ok=bfs();
        printf("%d\n",ok);
    }
    return 0;
}
