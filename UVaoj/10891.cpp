#include<iostream>
#include<cstdio>
#include<cstring>
#define INF -10000000000000
using namespace std;
int n;
long long a[120],d[120][120],sum[120];
long long dp(int i,int j)
{
    long long m;
    if(j==i)return d[i][j]=a[i];
    else if(j<i)return 0;
    else if(d[i][j]!=INF)return d[i][j];
    else
    {
        m=INF;
        for(int k=i; k<=j; k++)
            m=max(m,sum[k]-sum[i]+a[i]-dp(k+1,j));
        for(int k=j; k>=i; k--)
        m=max(m,sum[j]-sum[k]+a[k]-dp(i,k-1));
    }
    return d[i][j]=m;
}
int main()
{
   // freopen("1.txt","r",stdin);
    while(cin>>n&&n)
    {
        cin>>a[0];
        sum[0]=a[0];
        for(int i=1; i<n; i++)
        {
            cin>>a[i];
            sum[i]=sum[i-1]+a[i];
        }
        for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
        d[i][j]=INF;
        dp(0,n-1);
        cout<<d[0][n-1]<<endl;
    }
    return 0;
}
