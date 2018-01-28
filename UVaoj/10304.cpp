#include<iostream>
#include<cstring>
#include<cstdio>
#define INF (1<<31)-1
using namespace std;
int n,a[260],d[260][260],sum[260];
int dp(int i,int j)
{
    if(i>j)return 0;
    if(d[i][j]<INF)return d[i][j];
    int m=INF;
    for(int k=i; k<=j; k++)
        m=min(m,dp(i,k-1)+dp(k+1,j)+sum[j]-sum[i]+a[i]);
    return d[i][j]=m;
}
int main()
{
   //  freopen("1.txt","r",stdin);
    while(cin>>n)
    {
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
            if(!i)sum[i]=a[i];
            else sum[i]=sum[i-1]+a[i];
            for(int j=0; j<n; j++)
                d[i][j]=INF;
        }
        cout<<dp(0,n-1)-sum[n-1]<<endl;
    }
    return 0;
}
