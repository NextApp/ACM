#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define INF 1<<30
using namespace std;
int d[5050][1050],a[5050],n,k;
int dp(int i,int j,int s)
{
    if(d[i][j]>=0)return d[i][j];
    if(i>=2&&j>=1)
    {
        int m=INF,l;
        if(s>k+8-j)m=dp(i-2,j-1,s)+(a[i]-a[i-1])*(a[i]-a[i-1]);
        if(i>2&&j<=(i-1)/2)m=min(dp(i-1,j,s+1),m);
        return d[i][j]=m;
    }
    else return d[i][j]=0;
}
int main()
{
    int T;
   // freopen("1.txt","r",stdin);
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&k,&n);
        for(int i=1; i<=n; i++)
            scanf("%d",&a[i]);
        memset(d,-1,sizeof(d));
        printf("%d\n",dp(n,k+8,0));
    }
    return 0;
}
