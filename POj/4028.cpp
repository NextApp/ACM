#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,prime[10020],vis[10020];
int main()
{
    // freopen("1.txt","r",stdin);
    while(scanf("%d",&n)==1)
    {
        int cnt=0;
        memset(vis,0,sizeof(vis));
        for(int i=2; i<=n; i++)
            if(!vis[i])
            {
                prime[cnt++]=i;
                for(int j=i+i; j<=n; j+=i)
                    vis[j]=i;
            }
        int sum=0,i=0,j=cnt-1;
        while(i<=j)
        {
            int s=prime[i];
            int ok=0;
            while(j>=0&&s*prime[j]<=n)
                s*=prime[j--],ok=1;
            sum++;
            if(ok)i++;
            else j--;
        }
        printf("%d\n",sum);
    }
    return 0;
}
