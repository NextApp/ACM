#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
#define lson l,m,p<<1
#define rson m+1,r,p<<1|1
#define N 120
using namespace std;
int n,prime[N];
long long c[N],a,b;
void prime_in()
{
    memset(prime,0,sizeof(prime));
    prime[1]=1;
    for(int i=2; i<=10; i++)
        if(!prime[i])
            for(int j=i*i; j<=100; j+=i)
                prime[j]=i;
}
int P(long long m,long long a,long long n)
{
    long long s=0,l=a;
    while(m>=a)
    {
        s+=m/a;
        a*=l;
    }
    if(s>=n)return 1;
    else return 0;
}
long long b_search(long long a,long long s)
{
    long long b=1,e=(long long )1<<62;
    while(b<=e)
    {
        long long k=(b+e)/2;
        long long u=P(k,a,s),d=P(k-1,a,s);
        if(u&&!d)return k;
        else if(d)e=k-1;
        else b=k+1;
    }
    return b;
}
int main()
{
 //  freopen("1.txt","r",stdin);
    int T;
    prime_in();
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        memset(c,0,sizeof(c));
        for(int i=0; i<n; i++)
        {
            cin>>a>>b;
            long long m=a;
            while(m!=1&&prime[m])
            {
                c[prime[m]]+=b;
                m/=prime[m];
            }
            if(!prime[m])c[m]+=b;
        }
        long long mm=0;
        for(int i=2; i<100; i++)
            if(c[i])mm=max(b_search(i,c[i]),mm);
        cout<<mm<<endl;
    }
    return 0;
}
