#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 10020
#define MOD 1000000007
using namespace std;
int M[maxn],k,fact_num,result;
long long n,A[20],a[20],prime[2000];
long long d[]={2,3,5};
void prime_in()
{
    k=0;
    for(int i=2; i<=10000; i++)
        if(!M[i])
        {
            prime[k++]=i;
            for(int j=i*i; j<=10000; j+=i)
                M[j]=i;
        }
}
long long qiumod(long long a,long long b,long long c,long long d)
{
    return (((((a*b)%MOD)*c)%MOD)*d)%MOD;
}
long long SumN4(long long n)
{
    long long a=n+1,b=2*n+1,c=3*n*n+3*n-1;
    for(int i=0;i<3;i++)
    {
        int ok=1;
        if(n%d[i]==0&&ok)n/=d[i],ok=0;
        if(a%d[i]==0&&ok)a/=d[i],ok=0;
        if(b%d[i]==0&&ok)b/=d[i],ok=0;
        if(c%d[i]==0&&ok)c/=d[i],ok=0;
    }
    a%=MOD;
    b%=MOD;
    c%=MOD;
    return qiumod(n,a,b,c);
}
void prime_factor(long long n)
{
    fact_num=0;
    for(int i=0;i<k&&prime[i]<=n;i++)
    if(n%prime[i]==0)
    {
        A[fact_num++]=prime[i];
        while(n%prime[i]==0)n/=prime[i];
    }
    if(n!=1)A[fact_num++]=n;
}
void print_subset(int num,int cur)
{
    long long f=1;
    for(int i=0;i<cur;i++)
    f*=A[a[i]];
    long long u=(qiumod(f,f,f,f)*SumN4(n/f))%MOD;
    if(cur%2)result=(result-u)%MOD;
    else result=(result+u)%MOD;
    int s=cur?a[cur-1]+1:0;
    for(int i=s;i<num;i++)
    {
        a[cur]=i;
        print_subset(num,cur+1);
    }
}
int main()
{
    int T;
    prime_in();
    scanf("%d",&T);
    while(T--)
    {
        scanf("%lld",&n);
        result=0;
        prime_factor(n);
        print_subset(fact_num,0);
        result=(result+MOD)%MOD;
        printf("%lld\n",result);
    }
    return 0;
}
