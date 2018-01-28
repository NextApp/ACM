#include<iostream>
#include<cstdio>
#include<cstring>
#define N 210
#define INF 1020020
using namespace std;
int a[N],dmax[N][N],dmin[N][N],sum[N];
int dp(int i,int j)
{
    if(dmax[i][j])return dmax[i][j];
    if(i==j)return 0;
    else
    {
        int ans=0;
        for(int k=i;k<j;k++)
        {
            ans=max(dp(i,k)+dp(k+1,j),ans);
        }
        return dmax[i][j]=ans+sum[j]-sum[i]+a[i];
    }

}
int dp2(int i,int j)
{
    if(dmin[i][j])return dmin[i][j];
    if(i==j)return 0;
    else
    {
        int ans=INF;
        for(int k=i;k<j;k++)
        {
            ans=min(dp2(i,k)+dp2(k+1,j),ans);
        }
        return dmin[i][j]=ans+sum[j]-sum[i]+a[i];
    }

}
int main()
{
    //freopen("1.txt","r",stdin);
    int n;
    while(~scanf("%d",&n))
    {
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            a[i+n]=a[i];
            if(i)sum[i]=sum[i-1]+a[i];
            else sum[i]=a[i];
        }
        for(int i=n;i<2*n;i++)
        sum[i]=sum[i-1]+a[i-n];
        memset(dmax,0,sizeof(dmax));
        memset(dmin,0,sizeof(dmin));
        int mmax=0,mmin=INF;
        for(int i=0;i<n;i++)
        {
            mmax=max(mmax,dp(i,i+n-1));
            mmin=min(mmin,dp2(i,i+n-1));
        }
        printf("%d\n%d\n",mmin,mmax);
    }
    return 0;
}
