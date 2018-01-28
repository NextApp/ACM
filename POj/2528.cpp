#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
#define lson l,m,p<<1
#define rson m+1,r,p<<1|1
#define N 40000
using namespace std;
int vis[N],n,x[N],y[N],M[N],u,sum[100000];
short a[10001000];
void Update(int L,int R,int l,int r,int p)
{
    if(L<=l&&r<=R)
    {
        sum[p]=u;
        return ;
    }
    int m=(l+r)>>1;
    if(L<=m)Update(L,R,lson);
    if(R>m)Update(L,R,rson);
}
int query(int s,int t,int l,int r,int p)
{
    if(sum[p]>t)t=sum[p];
    if(l==r)return t;
    int m=(l+r)>>1;
    if(s<=m)return query(s,t,lson);
    else return query(s,t,rson);
}
int main()
{
    //freopen("1.txt","r",stdin);
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        memset(vis,0,sizeof(vis));
        memset(a,0,sizeof(a));
        memset(sum,0,sizeof(sum));
        int t=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&x[i],&y[i]);
            M[t++]=x[i],M[t++]=y[i];
        }
        sort(M,M+t);
        for(int i=0;i<t;i++)
        if(!a[M[i]])a[M[i]]=i+1;
        for(u=1;u<=n;u++)
         Update(a[x[u-1]],a[y[u-1]],1,t,1);
        for(int i=1;i<=t;i++)
        vis[query(i,0,1,t,1)]=1;
        int s=0;
        for(int i=1;i<=t;i++)
        if(vis[i])s++;
        printf("%d\n",s);
    }
    return 0;
}
