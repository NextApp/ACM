#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#include<iostream>

using namespace std;

const long long maxn = 400010;
long long c_len;
struct node
{
    long long x, n;
} c_op[1200];
long long prime[maxn], plen;
long long vis[maxn];

void mklist()
{
    memset(vis, 0, sizeof(vis));
    plen = 0;
    for(long long i = 2; i * i <=maxn; ++i)
    {
        if(!vis[i])
        {
            for(long long j=i+i; j<=maxn; j+=i)
                vis[j] = i;
        }
    }
}
long long fac[100], flen;
long long x, y, p;
long long get(long long n)
{
    long long xx=(x-1)/n;
    long long yy=y/n;
    long long xsum,ysum;
    if(xx==0)xsum=0;
    else xsum=(long long)n*(xx)*(xx+1)/2;
    ysum=(long long)n*yy*(yy+1)/2;
    return ysum-xsum;
}
long long v[404000];
void split(long long n)
{
    flen = 0;
    long long s=vis[n],t=n;
    if(s==0)
    {
        fac[flen++]=n;
    }
    else
    {
        while(1)
        {
            s=vis[t];
            if(!s)break;
            if(!v[s])
            {
                fac[flen++]=s;
                v[s]=1;
            }
            t=t/s;
        }
        if(t>1)
        {
            if(!v[t])fac[flen++]=t;
        }
    }
    for(long long i=0; i<flen; i++)
        v[fac[i]]=0;
}
long long A[100];
long long sum=0;
void print_subset(long long n,long long cur)
{
    long long ss=1;
    for(long long i=0; i<cur; i++)
        ss*=fac[A[i]];
    if(cur%2==0)
    {
        if(cur)sum-=get(ss);
    }
    else sum+=get(ss);
    long long s=cur?A[cur-1]+1:0;
    for(long long i=s; i<n; i++)
    {
        A[cur]=i;
        print_subset(n,cur+1);
    }
}
long long gcd(long long a,long long b)
{
    return b==0?a:gcd(b,a%b);
}
long long U[maxn];
long long PP[1200];
int main()
{
   // freopen("1.txt","r",stdin);
    mklist();
    int T;
    scanf("%d", &T);
    while(T--)
    {
        long long n, m;
        memset(v,0, sizeof(v));
        c_len=0;
        scanf("%I64d%I64d", &n, &m);
        for(long long i=1; i<=n; i++)U[i]=i;
        for(long long i = 0; i < m; ++i)
        {
            long long op;
            scanf("%I64d", &op);
            if(op == 1)
            {
                scanf("%I64d%I64d%I64d", &x, &y, &p);
                long long result=0;
                long long Sum=(long long)(y+1)*y/2-(long long)x*(x-1)/2;
                split(p);
                if(p==1)result=Sum;
                else
                {
                    sum=0;
                    print_subset(flen,0);
                    result=Sum-sum;
                }
                long long Pnum=0;
                for(long long j=0; j<c_len; j++)
                {
                    long long xx=c_op[j].x,cc=c_op[j].n;
                    if(xx>=x&&xx<=y)
                    {
                        if(gcd(p,cc)==1)result+=cc;
                        if(gcd(p,U[xx])==1)result-=U[xx];
                    }
                    U[xx]=cc;
                    if(xx!=cc)PP[Pnum++]=xx;
                }
                for(long long j=0; j<Pnum; j++)
                    U[PP[j]]=PP[j];
                printf("%I64d\n",result);
            }
            else
            {
                long long x, c;
                scanf("%I64d%I64d", &x, &c);
                c_op[c_len].x=x,c_op[c_len++].n=c;
            }
        }
    }
    return 0;
}
