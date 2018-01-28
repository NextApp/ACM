#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define maxn 400000
#define lson l,m,p<<1
#define rson m+1,r,p<<1|1
using namespace std;
int n,Q,sum[maxn],col[maxn],x,y,z;
void PushUP(int p)
{
    sum[p]=sum[p<<1]+sum[p<<1|1];
}
void PushDown(int m,int p)
{
    col[p<<1] = col[p<<1|1] = col[p];
    sum[p<<1] = (m - (m >> 1)) * col[p];
    sum[p<<1|1] = (m >> 1) * col[p];
    col[p] = 0;
}
void build(int l,int r,int p)
{
    col[p]=0;
    sum[p]=1;
    if(l==r)return ;
    int m=(l+r)>>1;
    build(lson);
    build(rson);
    PushUP(p);
}
void Update(int s,int L,int R,int l,int r,int p)
{
    if(L<=l&&r<=R)
    {
        col[p]=s;
        sum[p]=(r-l+1)*s;
        return ;
    }
    if(col[p])PushDown(r-l+1,p);
    int m=(l+r)>>1;
    if(L<=m)Update(s,L,R,lson);
    if(R>m)Update(s,L,R,rson);
    PushUP(p);
}
int main()
{
   // freopen("1.txt","r",stdin);
    int T,id=1;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&Q);
        build(1,n,1);
        for(int i=0; i<Q; i++)
        {
            scanf("%d%d%d",&x,&y,&z);
            Update(z,x,y,1,n,1);
        }
        printf("Case %d: The total value of the hook is %d.\n",id++,sum[1]);
    }
    return 0;
}
