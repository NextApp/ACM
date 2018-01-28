#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define lson l,m,p<<1
#define rson m+1,r,p<<1|1
#define maxn 5050
using namespace std;
int sum[maxn*4],a[maxn],n,m[maxn];
void PushUP(int p)
{
    sum[p]=sum[p<<1]+sum[p<<1|1];
}
void Update(int s,int v,int l,int r,int p)
{
    if(l==r)
    {
        sum[p]=v;
        return ;
    }
    int m=(l+r)>>1;
    if(m>=s)Update(s,v,lson);
    else Update(s,v,rson);
    PushUP(p);
}
int query(int L,int R,int l,int r,int p)
{
    if(L<=r&&r<=R)return sum[p];
    int m=(l+r)>>1,ans=0;
    if(m>=L)ans+=query(L,R,lson);
    if(R>m)ans+=query(L,R,rson);
    return ans;
}
int main()
{
  // freopen("1.txt","r",stdin);
    while(scanf("%d",&n)==1)
    {
        for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
        memset(sum,0,sizeof(sum));
        int l=0;
        for(int i=n-1;i>=0;i--)
        {
           Update(a[i]+1,1,1,n,1);
           m[i]=query(1,a[i]+1,1,n,1)-1;
           l+=m[i];
        }
        int s=l;
        for(int i=0;i<n;i++)
        {
            s=s+n-a[i]-a[i]-1;
            l=min(s,l);
        }
        printf("%d\n",l);
    }
    return 0;
}
