#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define lson l,m,p<<1
#define rson m+1,r,p<<1|1
#define maxn 100100
#define MOD 1000000007
using namespace std;
int n,sortnum[maxn],data[maxn];
long long sum[maxn<<2];
bool cmp(const int i,const int j)
{
    if(data[i]!=data[j])return data[i]<data[j];
    else return i<j;
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
    sum[p]=(sum[p<<1]+sum[p<<1|1])%MOD;
}
long long query(int R,int l,int r,int p)
{
    if(r<=R)return sum[p];
    int m=(l+r)>>1,ans=0;
    if(1<=m)ans=query(R,lson);
    if(m<R)ans+=query(R,rson);
    return ans%MOD;
}
int main()
{
    while(scanf("%d",&n)==1)
    {
        memset(sum,0,sizeof(sum));
        for(int i=0; i<n; i++)
        {
            scanf("%d",&data[i]);
            sortnum[i]=i;
        }
        sort(sortnum,sortnum+n,cmp);
        long long result=0,m;
        for(int i=0; i<n; i++)
        {
            m=sortnum[i]?query(sortnum[i],1,n,1):0;
            Update(sortnum[i]+1,m+1,1,n,1);
            result=(result+m+1)%MOD;
        }
        printf("%lld\n",result);
    }
    return 0;
}
