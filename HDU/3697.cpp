#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 55000
#define lson l,m,p<<1
#define rson m+1,r,p<<1|1
#define all 1,n-2,1
using namespace std;
int n,m,sum[300000],num;
char M[maxn];
void PushUP(int p)
{
    sum[p]=sum[p<<1]+sum[p<<1|1];
}
void build(int l,int r,int p)
{
    if(l==r)
    {
        if(num+2<n&&M[num]=='w'&&M[num+1]=='b'&&M[num+2]=='w')sum[p]=1;
        else sum[p]=0;
        num++;
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
        sum[p]=v;
        return;
    }
    int m=(l+r)>>1;
    if(s<=m)Update(s,v,lson);
    else Update(s,v,rson);
    PushUP(p);
}
int query(int L,int R,int l,int r,int p)
{
    if(L<=l&&r<=R)return sum[p];
    int m=(l+r)>>1,ans=0;
    if(L<=m)ans+=query(L,R,lson);
    if(R>m)ans+=query(L,R,rson);
    return ans;
}
int main()
{
 freopen("1.txt","r",stdin);
    int T,id=1;
    scanf("%d",&T);
    while(T--)
    {
        num=0;
        scanf("%d%d%s",&n,&m,M);
        if(n>2)build(all);
        int a,b;
        printf("Case %d:\n",id++);
        for(int i=0; i<m; i++)
        {
            scanf("%d%d",&a,&b);
            if(a==1)
            {
                char c;
                scanf(" %c",&c);
                M[b]=c;
                if(n<=2)continue;
                if(b+2<n)
                {
                    if(M[b]=='w'&&M[b+1]=='b'&&M[b+2]=='w')Update(b+1,1,all);
                    else Update(b+1,0,all);
                }
                if(b>=1&&b+1<n)
                {
                    if(M[b-1]=='w'&&M[b]=='b'&&M[b+1]=='w')Update(b,1,all);
                    else Update(b,0,all);
                }
                if(b>=2)
                {
                    if(M[b]=='w'&&M[b-1]=='b'&&M[b-2]=='w')Update(b-1,1,all);
                    else Update(b-1,0,all);
                }
            }
            else if(a==0)
            {
                int c;
                scanf("%d",&c);
                if(n<=2)continue;
                if(c-b<2)
                {
                    printf("0\n");
                    continue;
                }
                printf("%d\n",query(b+1,c-1,1,n-2,1));
            }
        }
    }
    return 0;
}
