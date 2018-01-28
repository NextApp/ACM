#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define lson l,m,p<<1
#define rson m+1,r,p<<1|1
#define maxn 300000
using namespace std;
long long sum[maxn],col[maxn];
void PushUP(int p)
{
    sum[p]=sum[p<<1]+sum[p<<1|1];
}
void PushDown(int m,int p)
{
    col[p<<1]+=col[p];
    col[p<<1|1]+=col[p];
    sum[p<<1]+=(m-(m>>1))*col[p];
    sum[p<<1|1]+=(m>>1)*col[p];
    col[p]=0;
}
void build(int l,int r,int p)
{
    col[p]=0;
    if(l==r)
    {
        scanf("%lld",&sum[p]);
        return;
    }
    int m=(l+r)>>1;
    build(lson);
    build(rson);
    PushUP(p);
}
void Update(long long s,int L,int R,int l,int r,int p)
{
    if(L<=l&&r<=R)
    {
        col[p]+=s;
        sum[p]+=s*(long long)(r-l+1);
        return;
    }
    if(col[p])PushDown(r-l+1,p);
    int m=(l+r)>>1;
    if(L<=m)Update(s,L,R,lson);
    if(R>m)Update(s,L,R,rson);
    PushUP(p);
}
long long query(int L,int R,int l,int r,int p)
{
    if(L<=l&&r<=R)return sum[p];
    if(col[p])PushDown(r-l+1,p);
    int m=(l+r)>>1;
    long long ans=0;
    if(L<=m)ans+=query(L,R,lson);
    if(R>m)ans+=query(L,R,rson);
    return ans;
}
int main()
{
   // freopen("1.txt","r",stdin);
    int n,m;
    while(scanf("%d%d",&n,&m)==2)
    {
        memset(sum,0,sizeof(sum));
        build(1,n,1);
        char d;
        int a,b;
        long long c;
        while(m--)
        {
            scanf(" %c",&d);
            if(d=='Q')
            {
                scanf("%d%d",&a,&b);
                printf("%lld\n",query(a,b,1,n,1));
            }
            else
            {
                scanf("%d%d%lld",&a,&b,&c);
                Update(c,a,b,1,n,1);
            }
        }
    }
    return 0;
}
