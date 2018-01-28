#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define lson l,m,p<<1
#define rson m+1,r,p<<1|1
#define maxn 220000
using namespace std;
int sum[3*maxn],n,M[maxn];
struct T
{
    int a,b;
}A[maxn];
void PushUP(int p)
{
    sum[p]=sum[p<<1]+sum[p<<1|1];
}
void build(int l,int r,int p)
{
    if(l==r)
    {
        sum[p]=1;
        return ;
    }
    int m=(l+r)>>1;
    build(lson);
    build(rson);
    PushUP(p);
}
int query(int s,int l,int r,int p)
{
    if(l==r)
    {
        sum[p]=0;
        return l;
    }
    int m=(l+r)>>1,ans;
    if(sum[p<<1]>=s)ans=query(s,lson);
    else ans=query(s-sum[p<<1],rson);
    PushUP(p);
    return ans;
}
int main()
{
    freopen("1.txt","r",stdin);
    while(scanf("%d",&n)==1)
    {
        build(1,n,1);
        for(int i=0;i<n;i++)
        scanf("%d%d",&A[i].a,&A[i].b);
        for(int i=n-1;i>=0;i--)
            M[query(A[i].a+1,1,n,1)]=A[i].b;
        for(int i=1;i<n;i++)
        printf("%d ",M[i]);
        printf("%d\n",M[n]);
    }
    return 0;
}
