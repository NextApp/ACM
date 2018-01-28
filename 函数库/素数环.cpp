#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int C[30],A[100],n,vis[30];
int dfs(int cur)
{
    if(n==cur&&A[C[cur-1]+C[0]])
    {
        for(int i=0; i<cur; i++)
            if(i<cur-1)cout<<C[i]<<' ';
            else cout<<C[i]<<endl;
    }
    else
    {
        for(int i=2; i<=n; i++)
        {
            int ok=1;
            C[cur]=i;
            if(A[C[cur]+C[cur-1]]&&!vis[i])
            {
                vis[i]=1;
                dfs(cur+1);
                vis[i]=0;
            }
        }
    }
}
int main()
{
    memset(A,-1,sizeof(A));
    for(int i=2; i<10; i++)
        for(int j=2*i; j<100; j+=i)
            A[j]=0;
    A[1]=0;
    while(cin>>n)
    {
        memset(vis,0,sizeof(vis));
        C[0]=1;
        dfs(1);
    }
    return 0;
}
