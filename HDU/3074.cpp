#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define maxn 50050
#define all 1,n,1
#define lson l,m,p<<1
#define rson m+1,r,p<<1|1
#define MOD 1000000007
using namespace std;
int n;
long long sum[maxn<<2];
void PushUP(int p)
{
    sum[p]=sum[p<<1]*sum[p<<1|1]%MOD;
}
void build(int l,int r,int p)
{
    if(l==r)
    {
        scanf("%lld",&sum[p]);
        return ;
    }
    int m=(l+r)>>1;
    build(lson);
    build(rson);
    PushUP(p);
}
void Update(int s,long long v,int l,int r,int p)
{
    if(l==r)
    {
        sum[p]=v;
        return ;
    }
    int m=(l+r)>>1;
    if(s<=m)Update(s,v,lson);
    else Update(s,v,rson);
    PushUP(p);
}
long long query(int L,int R,int l,int r,int p)
{
    if(L<=l&&r<=R)return sum[p];
    int m=(l+r)>>1;
    long long ans=1;
    if(L<=m)ans=query(L,R,lson);
    if(R>m)ans*=query(L,R,rson);
    return ans%MOD;
}
int main()
{
  //  freopen("1.txt","r",stdin);
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        build(all);
        int m;
        scanf("%d",&m);
        while(m--)
        {
            int c,a,b;
            scanf("%d%d%d",&c,&a,&b);
            if(c)Update(a,b,all);
            else printf("%lld\n",query(a,b,all));
        }
    }
    return 0;
}
