#include<stdio.h>
#include<string.h>
#include<iostream>
#include<queue>
using namespace std;
bool dp[23110][105];
int w[105],A[23000][55];
int a[23000],cur[23000],C[23000];
int main()
{
    freopen("1.txt","r",stdin);
    int i,j,k,l,m,n,sum,r,id=0;
    scanf("%d",&m);
    while(m--)
    {
        scanf("%d",&n);
        if(id)printf("\n");
        id=1;
        sum=0;
        r=(n+1)/2;
        int size=0;
        a[size++]=0;
        for(i=0; i<n; i++)
        {
            scanf("%d",&w[i]);
            sum+=w[i];
        }
        memset(C,0,sizeof(C));
        memset(cur,0,sizeof(cur));
        memset(dp,false,sizeof(dp));
        C[0]=cur[0]=dp[0][0]=1;
        A[0][0]=0;
        for(i=0; i<n; i++)
        {
            int sizenum=size;
            for(j=0; j<sizenum; j++)
            {
                int x=a[j]+w[i],u=a[j];
                if(x>sum/2)continue;
                for(int k=0; k<cur[u]; k++)
                {
                    int s=A[u][k]+1;
                    if(!dp[x][s])
                    {
                        dp[x][s]=1;
                        if(s<r)
                        {
                            if(!C[x])a[size++]=x;
                            A[x][C[x]++]=s;
                        }
                    }
                }
            }
            memcpy(cur,C,sizeof(C));
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
