#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a[120],sum,OK,n,nm,vis[120];
int cmp(int a,int b)
{
    return a>b;
}
int dfs(int cur,int nsum,int u)
{
    if(u==sum/nm)return OK=1;
    if(OK)return 0;
    for(int i=cur; i<n; i++)
    {
        if(!vis[i]&&nsum+a[i]<=nm)
        {
            vis[i]=1;
            if(nsum+a[i]==nm)
            {
                if(dfs(0,0,u+1))return 1;
            }
            else if(dfs(i+1,nsum+a[i],u))return 1;
            vis[i]=0;
            if(nsum+a[i]==nm)return 0;
            if(!nsum)return 0;
            while(a[i+1]==a[i])i++;
        }
    }
    return 0;
}
int main()
{
   // freopen("1.txt","r",stdin);
    while(cin>>n&&n)
    {
        sum=0;
        int m=0;
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
            sum+=a[i];
            m=max(m,a[i]);
        }
        sort(a,a+n,cmp);
        OK=0;
        memset(vis,0,sizeof(vis));
        for(nm=m; nm<=sum&&!OK; nm++)
            if(sum%nm==0)
            {
                dfs(0,0,1);
            }

        cout<<nm-1<<endl;
    }
    return 0;
}
