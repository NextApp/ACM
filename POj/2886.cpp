#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#define maxn 550000
#define lson l,m,p<<1
#define rson m+1,r,p<<1|1
using namespace std;
int n,k,prime[maxn],result,M[maxn],ln,ss;
char a[maxn][12];
struct T
{
    int n,a;
} s[100];
struct Node
{
    int id,n;
} sum[3*maxn];
void prime_data()
{
    memset(prime,0,sizeof(prime));
    for(int i=2; i<=750; i++)
        if(!prime[i])for(int j=i*i; j<=500000; j+=i)
                prime[j]=i;
}
void prime_in()
{
    result=ss=1;
    if(n==1)return;
    for(int j=n/2+1; j<=n; j++)
    {
        int l=j,num=1;
        while(1)
        {
            int k=l,t=1;
            while(prime[l]&&k%prime[l]==0)
            {
                t++;
                k/=prime[l];
            }
            num*=t;
            if(!prime[k])
            {
                if(k!=1)num*=2;
                break;
            }
            else l=k;
        }
        if(ss<num)result=j,ss=num;
    }
}
void PushUP(int p)
{
    sum[p].n=sum[p<<1].n+sum[p<<1|1].n;
}
void build(int l,int r,int p)
{
    if(l==r)
    {
        sum[p].n=1;
        sum[p].id=ln++;
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
        sum[p].n=0;
        return sum[p].id;
    }
    int ans,m=(l+r)>>1;
    if(s<=sum[p<<1].n)ans=query(s,lson);
    else ans=query(s-sum[p<<1].n,rson);
    PushUP(p);
    return ans;
}
int main()
{
    // freopen("1.txt","r",stdin);
    prime_data();
    while(scanf("%d%d",&n,&k)==2)
    {
        prime_in();
        ln=1;
        for(int i=1; i<=n; i++)
            scanf("%s%d",a[i],&M[i]);
        build(1,n,1);
        int t=0,u=k,w;
        while(t<result)
        {
            w=query(u,1,n,1);
            int s=n-t-1;
            if(!s)break;
            if(M[w]<0)u=(M[w]+u)%s;
            else u=(M[w]+u-1)%s;
            u=(u+s)%s;
            if(!u)u=s;
            t++;
        }
        printf("%s %d\n",a[w],ss);
    }
    return 0;
}

