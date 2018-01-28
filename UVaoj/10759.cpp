#include<iostream>
#include<cstdio>
#include<cstring>
#define ULL unsigned long long
using namespace std;
int vis[1200],n;
void dfs(int cur,int s)
{
    if(cur==0)
    {
        vis[s]++;
        return;
    }
    for(int i=1;i<=6;i++)
    dfs(cur-1,s+i);
}
ULL d[30][200],sum[30];
ULL gcd(ULL a,ULL b)
{
    return b==0?a:gcd(b,a%b);
}
int main()
{
    memset(d,0,sizeof(d));
    memset(sum,0,sizeof(sum));
    n=24;
    int a,b;
    for(int i=1;i<=6;i++)d[1][i]=1;
    for(int i=2;i<=n;i++)
    for(int j=i;j<=i*6;j++)
    for(int t=1;t<=6;t++)
    if(j>=t)d[i][j]+=d[i-1][j-t];
    for(int i=1;i<=24;i++)
    for(int j=i;j<=i*6;j++)
    sum[i]+=d[i][j];
    while(~scanf("%d%d",&a,&b)&&a+b)
    {
        unsigned long long x=0,s=sum[a];
        for(int i=b;i<=a*6;i++)
        x+=d[a][i];
        unsigned long long ans=gcd(x,s);
        if(x==s)printf("1\n");
        else if(!x)printf("0\n");
        else
        {if(ans)x/=ans;
        if(ans)s/=ans;
        cout<<x<<'/'<<s<<endl;}
    }
    return 0;
}
