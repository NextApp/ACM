#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define maxn 400000
#define lson l,m,p<<1
#define rson m+1,r,p<<1|1
using namespace std;
int n,Q,x,y,z,u;
struct T
{
    int v,order;
} sum[maxn];
void Update(int s,int L,int R,int l,int r,int p)
{
    if(L<=l&&r<=R)
    {
        sum[p].v=s;
        sum[p].order=u;
        return ;
    }
    int m=(l+r)>>1;
    if(L<=m)Update(s,L,R,lson);
    if(R>m)Update(s,L,R,rson);
}
int query(int s,int v,int d,int l,int r,int p)
{
    if(sum[p].order>d)
    {
        d=sum[p].order;
        v=sum[p].v;
    }
    if(l==r)return v;
    int m=(l+r)>>1;
    if(s<=m)return query(s,v,d,lson);
    else return query(s,v,d,rson);
}
int main()
{
  //  freopen("1.txt","r",stdin);
    int T,id=1;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&Q);
        memset(sum,0,sizeof(sum));
        for(u=1; u<=Q; u++)
        {
            scanf("%d%d%d",&x,&y,&z);
            Update(z,x,y,1,n,1);
        }
        int s=0;
        for(int i=1; i<=n; i++)
            s+=query(i,1,0,1,n,1);
        printf("Case %d: The total value of the hook is %d.\n",id++,s);
    }
    return 0;
}
