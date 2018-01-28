#include<iostream>
#include<cstdio>
#include<cstring>
#define N 1048576
using namespace std;
struct node
{
    int ok,num,data,M[100];
} q[N];
int topo[N],vis[N],ss;
void dfs(int u)
{
    vis[u]=1;
    for(int i=0; i<q[u].num; i++)
        if(!vis[q[u].M[i]])dfs(q[u].M[i]);
    topo[ss++]=u;
}
int main()
{
    int numcase;
    //freopen("1.txt","r",stdin);
    cin>>numcase;
    while(numcase--)
    {
        int m,n;
        cin>>n>>m;
        char a[1000];
        for(int i=0; i<n*m; i++)
        {
            cin>>a;
            q[i].num=0;
            if(a[0]=='=')
            {
                q[i].ok=0;
                int s=1,t=0;
                while(a[s])
                {
                    if(a[s]<='Z'&&a[s]>='A')t=26*t+a[s]-'A'+1;
                    else if(a[s]!='+')
                    {
                        int o=0;
                        while(a[s]&&a[s]<='9'&&a[s]>='0')
                        {
                            o=10*o+a[s]-'0';
                            s++;
                        }
                        t=(o-1)*n+t-1;
                        q[i].M[q[i].num++]=t;
                        continue;
                    }
                    else t=0;
                    s++;
                }
            }
            else
            {
                sscanf(a,"%d",&q[i].data);
                q[i].ok=1;
            }
        }
        ss=0;
        memset(vis,0,sizeof(vis));
        for(int i=0; i<n*m; i++)
            if(!vis[i])dfs(i);
        for(int i=0; i<n*m; i++)
        {
            if(!q[topo[i]].ok)
            {
                int u=0;
                for(int j=0; j<q[topo[i]].num; j++)
                    u+=q[q[topo[i]].M[j]].data;
                q[topo[i]].data=u;
            }
        }
        for(int i=0; i<m*n; i++)
        {
            if((i+1)%n==1)cout<<q[i].data;
            else cout<<' '<<q[i].data;
            if(i&&!((i+1)%n))cout<<endl;
        }
    }
    return 0;
}
