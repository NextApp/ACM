#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define lson l,m,p<<1
#define rson m+1,r,p<<1|1
#define maxn 550000
#define all 1,n,1
using namespace std;
int sum[maxn],rol[maxn],vis[140000];
void build(int l,int r,int p)
{
    if(l==r)
    {
        rol[p]=1;
        return;
    }
    int m=(l+r)>>1;
    build(lson);
    build(rson);
}
void judge(int p,int v)
{
    if(rol[p]&&v==-1)
    {
        if(sum[p]==-1)rol[p]=0;
        else sum[p]=!sum[p],rol[p]=1;
    }
    else sum[p]=v,rol[p]=1;
}
void PushDown(int p)
{
    judge(p<<1,sum[p]);
    judge(p<<1|1,sum[p]);
    rol[p]=0;
}
void Update(int L,int R,int v,int l,int r,int p)
{
    if(L<=l&&r<=R)
    {
        judge(p,v);
        return ;
    }
    if(rol[p])PushDown(p);
    int m=(l+r)>>1;
    if(L<=m)Update(L,R,v,lson);
    if(m<R)Update(L,R,v,rson);
}
int query(int s,int l,int r,int p)
{
    if((rol[p]&&sum[p]!=-1)||l==r)return sum[p];
    if(rol[p])PushDown(p);
    int m=(l+r)>>1;
    if(s<=m)return query(s,lson);
    else return query(s,rson);
}
int main()
{
   // freopen("1.txt","r",stdin);
    memset(sum,0,sizeof(sum));
    memset(rol,0,sizeof(rol));
    int a,b,n=65536*2;
    char le,ri,c,op;
    build(all);
    while(scanf(" %c %c%d%c%d%c",&op,&le,&a,&c,&b,&ri)==6)
    {
        ++a,++b;
        a<<=1,b<<=1;
        if(le=='(')a+=1;
        if(ri==')')b-=1;
        if(op=='U'&&a<=b)Update(a,b,1,all);
        else if(op=='D'&&a<=b)Update(a,b,0,all);
        else if(op=='S'&&a<=b)Update(a,b,-1,all);
        else
        {
            int aa=a-1,bb=b+1;
            Update(1,aa,0,all);
            Update(bb,n,0,all);
            if(op=='C'&&a<=b)Update(a,b,-1,all);
        }
    }
    for(int i=2; i<=n; i++)
        vis[i]=query(i,all);
    int ok=0;
    for(int i=2; i<=n; i++)
        if(vis[i])
        {
            int f=i,e;
            while(i<=n&&vis[i])e=i++;
            le='[',ri=']';
            if(f%2)le='(';
            if(e%2)ri=')',e++;
            f=f/2-1,e=e/2-1;
            if(!ok)printf("%c%d,%d%c",le,f,e,ri);
            else printf(" %c%d,%d%c",le,f,e,ri);
            ok=1;
        }
    if(ok) printf("\n");
    else printf("empty set\n");
    return 0;
}
