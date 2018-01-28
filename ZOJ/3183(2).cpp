#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define N 200300
using namespace std;
struct T
{
    int data,times,left,right,len;
} A[80000];
int prime_data,n,m,prime[N],a[N],cnt,O[20000];
void prime_cal()
{
    cnt=1;
    memset(prime,0,sizeof(prime));
    for(int i=2; i<=450; ++i)
    {
        if(!prime[i])
            for(int j=i*i; j<=200000; j+=i)
                prime[j]=i;
    }
    for(int i=2; i<200000; ++i)
        if(!prime[i])a[i]=cnt,O[cnt++]=i;
}
void Build(int l,int r,int p)
{
    A[p].left=l;
    A[p].right=r;
    A[p].len=r-l;
    A[p].data=1;
    if(A[p].len==1)A[p].times=0;
    else
    {
        int mid=(l+r)>>1;
        Build(l,mid,p<<1);
        Build(mid,r,(p<<1)+1);
    }
}
int POW(int p,int n)
{
    if(!n)return 1;
    int x=POW(p,n>>1);
    long long ans=(long long)x*x%m;
    if(n%2)return (long long)ans*p%m;
    return (int)ans;
}
void insert(int p,int nu,int ok)
{
    if(A[p].len>1)
    {
        int mid=(A[p].right+A[p].left)>>1;
        if(mid>nu)insert(p<<1,nu,ok);
        else insert((p<<1)+1,nu,ok);
        A[p].data=(long long)A[p<<1].data*A[(p<<1)+1].data%m;
    }
    else
    {
        if(ok)A[p].times++;
        else A[p].times--;
        A[p].data=POW(prime_data,A[p].times);
    }
}
int gcd(int a,int b)
{
    return b==0?a:gcd(b,a%b);
}
void change(int x,int ok)
{
    if(x==1)return ;
    int m=prime[x];
    while(m)
    {
        prime_data=m;
        x/=m;
        insert(1,a[m],ok);
        m=prime[x];
    }
    if(!m)
    {
        prime_data=x;
        insert(1,a[x],ok);
    }
}
void calculate()
{
    int sum=1,x,y;
    for(int i=2; i<=n; i++)
    {
        x=2*i-1;
        y=i+1;
        if(y%2==0)y=y>>1;
        else
        {
            prime_data=2;
            insert(1,a[2],1);
        }
        int g=gcd(x,y);
        x/=g;
        y/=g;
        change(x,1);
        change(y,0);
        sum=((long long )sum+A[1].data)%m;
    }
    printf("%d\n",sum);
}
int main()
{
   // freopen("1.txt","r",stdin);
    prime_cal();
    while(scanf("%d%d",&n,&m)==2)
    {
        if(!n&&!m)break;
        else
        {
            Build(1,lower_bound(O+1,O+cnt,2*n)-O+1,1);
            calculate();
        }
    }
    return 0;
}
