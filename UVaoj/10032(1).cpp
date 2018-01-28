#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
bool dp[23110][105];
int w[105];
struct T
{
    int a[55];
    int n;
} A[23000];
int main()
{
    //freopen("1.txt","r",stdin);
    int i,j,k,l,m,n,sum,r,id=0;
    scanf("%d",&m);
    while(m--)
    {
        scanf("%d",&n);
        if(id)printf("\n");
        id=1;
        sum=0;
        if(n%2==0)r=n/2;
        else r=n/2+1;
        for(i=0; i<n; i++)
        {
            scanf("%d",&w[i]);
            sum+=w[i];
        }
        for(int i=0; i<=sum/2+1; i++)A[i].n=0;
        memset(dp,false,sizeof(dp));
        A[0].n=1;
        A[0].a[0]=0;
        dp[0][0]=1;
        for(i=0; i<n; i++)
            for(j=sum/2+1; j>=w[i]; j--)
            {

                int u=j-w[i];
                for(int k=0; k<A[u].n; k++)
                    {
                        int s=A[u].a[k]+1;
                        if(!dp[j][s])
                        {
                            dp[j][s]=1;
                           if(s<r)A[j].a[A[j].n++]=s;
                        }
                    }
            }
        for(i=sum/2; i>=0; i--)
        {
            if(n%2==0)
            {
                if(dp[i][r]==1)break;
            }
            else
            {
                if(dp[i][r]==1||dp[i][r-1]==1)
                    break;
            }
        }
        printf("%d %d\n",i,sum-i);
    }
    return 0;
}
