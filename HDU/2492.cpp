#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 120200
using namespace std;
long long data[N],a[N],sum1[N],sum2[N];
int n,ma;
int Lowbit(int x)
{
    return x&-x;
}
long long Sum(int s)
{
    long long sum=0;
    while(s>=1)
    {
        sum+=a[s];
        s-=Lowbit(s);
    }
    return sum;
}
void Update(int s,long long v)
{
    while(s<=ma)
    {
        a[s]+=v;
        s+=Lowbit(s);
    }
}
int main()
{
   // freopen("1.txt","r",stdin);
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        ma=0;
        for(int i=1; i<=n; i++)
        {
            scanf("%lld",&data[i]);
            if(ma<data[i])ma=data[i];
        }
        long long sum=0;
        memset(a,0,sizeof(a));
        for(int i=1; i<=n; i++)
        {
            sum1[i]=Sum(data[i]);
            Update(data[i],1);
        }
        memset(a,0,sizeof(a));
        for(int i=n; i>=1; i--)
        {
            sum2[i]=Sum(ma)-Sum(data[i]-1);
            Update(data[i],1);
            long long s1=sum1[i],s2=sum2[i];
            sum+=s1*s2;
            sum+=(i-s1-1)*(n-i-s2);
        }
        cout<<sum<<endl;
    }
    return 0;
}
