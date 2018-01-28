#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int sum[50000],p[50000];
int find(int x)
{
    return p[x]==x?x:p[x]=find(p[x]);
}
int main()
{
   // freopen("1.txt","r",stdin);
    int T;
    cin>>T;
    while(T--)
    {
        memset(sum,0,sizeof(sum));
        int m,n;
        cin>>n>>m;
        for(int i=1; i<=n; i++)p[i]=i;
        int a,b;
        for(int i=0; i<m; i++)
        {
            cin>>a>>b;
            int x=find(a);
            int y=find(b);
            if(x!=y)
            {
                   p[x]=y;
                   sum[x]=sum[y]=sum[x]+sum[y]+1;
            }
        }
        int maxsum=0;
        for(int i=1; i<=n; i++)
                maxsum=maxsum<sum[i]?sum[i]:maxsum;
        cout<<maxsum+1<<endl;
    }
    return 0;
}
