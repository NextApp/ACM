#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define lson l,m,p<<1
#define rson m+1,r,p<<1|1
#define N 800000
using namespace std;
int n,m;
int sum[N];
void PushUP(int p)
{
    sum[p]=max(sum[p<<1],sum[p<<1|1]);
}
void build(int l,int r,int p)
{
    if(l==r)
    {
        scanf("%d",&sum[p]);
        return;
    }
    int m=(l+r)>>1;
    build(lson);
    build(rson);
    PushUP(p);
}
void Updata(int s,int val,int l,int r,int p)
{
    if(l==r)
    {
        sum[p]=val;
        return;
    }
    int m=(l+r)>>1;
    if(s<=m)Updata(s,val,lson);
    else Updata(s,val,rson);
    PushUP(p);
}
int query(int L,int R,int l,int r,int p)
{
    if(L<=l&&r<=R)return sum[p];
    int m=(l+r)>>1;
    int ans=0;
    if(L<=m)ans=max(ans,query(L,R,lson));
    if(R>m) ans=max(ans,query(L,R,rson));
    return ans;
}
int main()
{
   // freopen("1.txt","r",stdin);
    while(scanf("%d%d",&n,&m)==2)
    {
        build(1,n,1);
        char c;
        int a,b;
        while(m--)
        {
            scanf(" %c%d%d",&c,&a,&b);
            if(c=='Q')printf("%d\n",query(a,b,1,n,1));
            else Updata(a,b,1,n,1);
        }
    }
    return 0;
}
