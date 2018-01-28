#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define lson l,m,p<<1
#define rson m+1,r,p<<1|1
#define maxn 200000
using namespace std;
int n,h,w,num;
struct T
{
    int mm,id;
} sum[4*maxn];
void PushUP(int p)
{
    int s=p<<1,t=p<<1|1;
    if(sum[s].mm>=sum[t].mm)
    {
        sum[p].id=sum[s].id;
        sum[p].mm=sum[s].mm;
    }
    else
    {
        sum[p].id=sum[t].id;
        sum[p].mm=sum[t].mm;
    }
}
void build(int l,int r,int p)
{
    if(l==r)
    {
        sum[p].mm=w;
        sum[p].id=num++;
        return ;
    }
    int m=(l+r)>>1;
    build(lson);
    build(rson);
    PushUP(p);
}
void Update(int s,int v,int l,int r,int p)
{
    if(l==r)
    {
        sum[p].mm+=v;
        return ;
    }
    int m=(l+r)>>1;
    if(m>=s)Update(s,v,lson);
    else Update(s,v,rson);
    PushUP(p);
}
int query(int v,int l,int r,int p)
{
    if(l==r)return sum[p].id;
    int m=(l+r)>>1;
    if(v<=sum[p<<1].mm)return query(v,lson);
    else return query(v,rson);
}
int main()
{
   // freopen("1.txt","r",stdin);
    while(scanf("%d%d%d",&h,&w,&n)==3)
    {
        num=1;
        int s=h>n?n:h;
        build(1,s,1);
        int a;
        for(int i=0; i<n; i++)
        {
            scanf("%d",&a);
            if(a>sum[1].mm)printf("-1\n");
            else
            {
                int l=query(a,1,s,1);
                printf("%d\n",l);
                Update(l,-a,1,s,1);
            }
        }
    }
    return 0;
}
